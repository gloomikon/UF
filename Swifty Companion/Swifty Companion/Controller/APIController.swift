//
//  APIController.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/21/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import Foundation
import UIKit
import AuthenticationServices


class APIController {
    private let delegate: LoginController
    private var token: String?
    private var user: User?
    
    private let UID = "aca421ef55db61a13306c1ba22113fe9d3048a84b61a3d01c376c1fc4dca64e7"
    private let SECRET = "78aa60be8b774f7d9b98f56e4678c3e2d65e3db2c6aa2b169cd0d74c2c0eb378"
    private let siteUrl = "kolumbia://kolumbia"
    
    private var auth: ASWebAuthenticationSession?
    
    init(delegate: LoginController) {
        self.delegate = delegate
    }
    
    public func getToken() {
        let urlString = "https://api.intra.42.fr/oauth/authorize?client_id=\(UID)&redirect_uri=\(siteUrl)&response_type=code";
        auth = ASWebAuthenticationSession(url: URL(string: urlString)!, callbackURLScheme: siteUrl) {
            (data, error) in
            if data != nil {
                let session = URLSession.shared
                let url = NSURL(string: "https://api.intra.42.fr/oauth/token")
                let request = NSMutableURLRequest(url: url! as URL)
                request.httpBody = "grant_type=authorization_code&client_id=\(self.UID)&client_secret=\(self.SECRET)&\((data?.query!)!)&redirect_uri=\(self.siteUrl)".data(using: String.Encoding.utf8)
                request.httpMethod = "POST"
                session.dataTask(with: request as URLRequest) {
                    (data, res, err) in
                    if err != nil {
                        return
                    }
                    do {
                        if let dict: NSDictionary = try JSONSerialization.jsonObject(with: data!) as? NSDictionary {
                            print(dict)
                            self.token = dict["access_token"] as? String
                            if self.token != nil {
                                DispatchQueue.main.async {
                                    self.delegate.gotoSearchController()
                                }
                            }
                        }
                    } catch {
                        print("Error")
                    }
                }.resume()
            }
        }
        auth?.start()
    }
    
    public func getUserInfo(login: String) {
        let url = URL(string: "https://api.intra.42.fr/v2/users/\(login)/")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer " + self.token!, forHTTPHeaderField: "Authorization")
        let task = URLSession.shared.dataTask(with: request as URLRequest) {
            (data, response, error) in
            guard error == nil && data != nil else {
//                print(error!.localizedDescription)
                return
            }
            do {
                var skills : [Skill] = []
                var projects : [Project] = []
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
                    let grade = cursus_users!["grade"] as? String
                    let level = cursus_users!["level"] as! Double
                    let id = (cursus_users!["cursus"] as! NSDictionary)["id"] as! Int
                    let skillsJSON = (cursus_users!["skills"] as? [NSDictionary])!
                    for s in skillsJSON {
                        let name = s["name"] as! String
                        let level = s["level"] as! Double
                        skills.append(Skill(name: name, level: level))
                    }
                    let date = cursus_users!["begin_at"] as! String
                    let dateFormatter = DateFormatter()
                    dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss.SSSZ"
                    dateFormatter.locale = Locale(identifier: "en_US_POSIX")
                    let begin_at = dateFormatter.date(from: date)!
                    
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
                    
                    self.user = User(login: login, displayname: displayname, image_url: image_url, email: email, correction_point: correction_point, wallet: wallet, grade: grade, level: level, begin_at: begin_at, skills: skills, projects: projects)
                    print(self.user!.description)
                } else {
                    print("Error - invalid user")
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
