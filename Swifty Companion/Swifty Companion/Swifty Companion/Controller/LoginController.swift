import UIKit


class LoginController: UIViewController {
    @IBOutlet weak var connectBtn: UIButton!
    
    var apiLoginController: APILoginController?
    let layer = CAGradientLayer()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        apiLoginController = APILoginController(delegate: self)
        connectBtn.layer.cornerRadius = 10
        layer.frame = view.bounds
        layer.colors = [UIColor.white.cgColor, UIColor.purple.cgColor, UIColor.black.cgColor]
        view.layer.insertSublayer(layer, at: 0)
    }

    @IBAction func connect(_ sender: UIButton) {
        apiLoginController?.getToken()
    }
    
    public func gotoSearchController() {
        let searchViewController = self.storyboard?.instantiateViewController(withIdentifier: "search") as! SearchController
        self.navigationController!.pushViewController(searchViewController, animated: true)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        layer.frame = view.bounds
    }
    
}

