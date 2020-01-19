import Foundation

class APISearchController {
    let delegate: SearchController
    let token = serverData.token!
    
    init(delegate: SearchController) {
        self.delegate = delegate
    }
    
    public func getUserInfo(login: String) {
        let url = URL(string: "https://api.intra.42.fr/v2/users/\(login)/")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer " + self.token, forHTTPHeaderField: "Authorization")
        let task = URLSession.shared.dataTask(with: request as URLRequest) {
            (data, response, error) in
            guard error == nil && data != nil else { return }
            do {
                var skills : [Skill] = []
                var projects : [Project] = []
                var level: Double
                var grade: String?
                var begin_at: Date
                let json = try JSONSerialization.jsonObject(with: data!, options: []) as! [String: Any]
                if (json["first_name"] as? String) != nil {
                    
                    // Get bio
                    let login = json["login"] as! String
                    let displayname = json["displayname"] as! String
                    let image_url = json["image_url"] as! String
                    let email = json["email"] as! String
                    let correction_point = json["correction_point"] as! Int
                    let wallet = json["wallet"] as! Int
                    
                    // Get skills
                    let cursus_users_array = (json["cursus_users"] as? [NSDictionary])!
                    var cursus_users: NSDictionary?
                    for c in cursus_users_array {
                        let name = (c["cursus"] as! NSDictionary)["name"] as! String
                        if (name.contains("42")) {
                            cursus_users = c
                            break;
                        }
                    }
                    if let cursus_users = cursus_users {
                        grade = cursus_users["grade"] as? String
                        level = cursus_users["level"] as! Double
                        let id = (cursus_users["cursus"] as! NSDictionary)["id"] as! Int
                        let skillsJSON = (cursus_users["skills"] as? [NSDictionary])!
                        for s in skillsJSON {
                            let name = s["name"] as! String
                            let level = s["level"] as! Double
                            skills.append(Skill(name: name, level: level))
                        }
                        let date = cursus_users["begin_at"] as! String
                        let dateFormatter = DateFormatter()
                        dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss.SSSZ"
                        dateFormatter.locale = Locale(identifier: "en_US_POSIX")
                        begin_at = dateFormatter.date(from: date)!

                        // Get projects
                        let projectsJSON : [NSDictionary] = (json["projects_users"] as? [NSDictionary])!
                        for p in projectsJSON {
                            if self.suitableProject(project: p, id: id) {
                                let project = p["project"] as! NSDictionary
                                let name = project["slug"] as! String
                                let status = p["status"] as! String
                                let validated = p["validated?"] as? Bool
                                let mark = p["final_mark"] as? Int
                                projects.append(Project(name: name, status: status, validated: validated, mark: mark))
                            }
                        }
                    } else {
                        level = 0
                        begin_at = Date()
                    }

                    serverData.user = User(login: login, displayname: displayname, image_url: image_url, email: email, correction_point: correction_point, wallet: wallet, grade: grade, level: level, begin_at: begin_at, skills: skills, projects: projects)
                    print(serverData.user!.description)
                    DispatchQueue.main.async {
                        self.delegate.gotoBio()
                    }
                } else {
                    DispatchQueue.main.async {
                        self.delegate.loadingIndicator.stopAnimating()
                        self.delegate.displayError(message: "User not found")
                    }
                }
            } catch {
                return
            }
        }
        task.resume()
    }
    
    private func suitableProject(project: NSDictionary, id: Int) -> Bool {
        let cursus_ids = project["cursus_ids"] as! [Int]
        if cursus_ids.contains(id) {
            let parent_id = (project["project"] as! NSDictionary)["parent_id"] as? Int
            let status = project["status"] as! String
            return (parent_id == nil) && (status != "parent")
        }
        return false
    }
}
