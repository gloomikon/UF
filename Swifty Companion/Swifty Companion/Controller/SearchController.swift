import UIKit

class SearchController: UIViewController {
    @IBOutlet weak var searchBtn: UIButton!
    @IBOutlet weak var searchField: UITextField!
    
    var apiSearchController: APISearchController?
    let layer = CAGradientLayer()

    override func viewDidLoad() {
        super.viewDidLoad()
        apiSearchController = APISearchController(delegate: self)
        self.navigationItem.hidesBackButton = true
        searchBtn.layer.cornerRadius = 10
        layer.frame = view.bounds
        layer.colors = [UIColor.yellow.cgColor, UIColor.purple.cgColor, UIColor.black.cgColor]
        view.layer.insertSublayer(layer, at: 0)
    }
    
    @IBAction func search(_ sender: UIButton) {
        if (searchField.text == "") {
            displayError(message: "Field can not be empty")
        } else {
            apiSearchController?.getUserInfo(login: searchField.text!)
        }
    }
    
    public func gotoBio() {
        self.performSegue(withIdentifier: "gotoBio", sender: nil)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        layer.frame = view.bounds
    }
}
