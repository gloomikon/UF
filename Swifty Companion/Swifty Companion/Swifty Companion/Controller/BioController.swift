import UIKit

class BioController: UIViewController {

    // MARK: IBOutlet properties

    @IBOutlet weak var levelProgress: UIProgressView! {
        didSet {
            levelProgress.layer.cornerRadius = 10
            levelProgress.clipsToBounds = true
            levelProgress.progress = Float(serverData.user!.level - floor(serverData.user!.level))
        }
    }

    @IBOutlet weak var levelText: UILabel! {
        didSet {
            levelText.text = String(format: "%.2f", serverData.user!.level)
        }
    }

    @IBOutlet weak var photo: UIImageView! {
        didSet {
            photo.layer.cornerRadius = 50
        }
    }

    @IBOutlet weak var displayname: UILabel! {
        didSet {
            displayname.font = UIFont(name: "Helvetica-Bold", size: 20.0)
            displayname.textColor = .white
            displayname.text = serverData.user?.displayname
        }
    }

    @IBOutlet weak var login: UILabel! {
        didSet {
            login.font = UIFont(name: "Helvetica-Light", size: 20.0)
            login.textColor = .white
            login.text = serverData.user?.login
        }
    }

    @IBOutlet weak var infoView: UIView! {
        didSet {
            infoView.layer.cornerRadius = 10
        }
    }

    @IBOutlet weak var gradeLbl: UILabel! {
        didSet {
            gradeLbl.text = serverData.user!.grade ?? "No grade"
        }
    }

    @IBOutlet weak var walletLbl: UILabel! {
        didSet {
            walletLbl.text = "\(serverData.user!.wallet)₳"
        }
    }

    @IBOutlet weak var cpLbl: UILabel! {
        didSet {
            cpLbl.text = String(serverData.user!.correction_point)
        }
    }
    @IBOutlet weak var dateLbl: UILabel!

    @IBOutlet weak var emailLbl: UILabel! {
        didSet {
            emailLbl.text = serverData.user!.email
        }
    }

    @IBOutlet weak var skillsTableView: UITableView! {
        didSet {
            skillsTableView.layer.cornerRadius = 10
        }
    }
    
    @IBOutlet weak var projectsTableView: UITableView! {
        didSet {
            projectsTableView.layer.cornerRadius = 10
        }
    }

    @IBOutlet weak var loadingIndicator: UIActivityIndicatorView!

    // MARK: Life cycle events

    override func viewDidLoad() {
        super.viewDidLoad()
        let formatter = DateFormatter()
        formatter.dateFormat = "MMMM dd, yyyy"
        let dateStr = formatter.string(from: serverData.user!.begin_at)
        dateLbl.text = dateStr

        loadingIndicator.startAnimating()
        let url = URL(string: serverData.user!.image_url)
        URLSession.shared.dataTask(with: url!) {
            (data, resp, err) in
            guard let data = data, err == nil else {
                self.loadingIndicator.stopAnimating()
                return
            }
            DispatchQueue.main.async {
                self.loadingIndicator.stopAnimating()
                self.photo.image = UIImage(data: data)
            }
        }.resume()
    }
}

// MARK: Extensions

extension BioController: UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch tableView {
        case projectsTableView:
            return serverData.user!.projects.count
        case skillsTableView:
            return serverData.user!.skills.count
        default:
            return 0
        }

    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if tableView == skillsTableView {
            let cell = tableView.dequeueReusableCell(withIdentifier: "skillsCell") as! SkillsTableViewCell
            cell.nameLbl.text = serverData.user!.skills[indexPath.row].name
            cell.markLbl.text = String(format: "%.2f", serverData.user!.skills[indexPath.row].level)
            return cell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "projectsCell") as! ProjectsTableViewCell
            cell.nameLbl.text = serverData.user!.projects[indexPath.row].name
            switch serverData.user!.projects[indexPath.row].status {
            case "finished":
                if let mark = serverData.user!.projects[indexPath.row].mark {
                    cell.markLbl.text = String(mark)
                } else {
                    cell.markLbl.text = "0"
                }
                if let validated = serverData.user!.projects[indexPath.row].validated {
                    cell.markLbl.textColor = validated ? .green : .red
                } else {
                    cell.markLbl.textColor = .red
                }
            default:
                cell.markLbl.text = "In progress"
                cell.markLbl.textColor = .yellow
            }
            return cell
        }
    }


}
