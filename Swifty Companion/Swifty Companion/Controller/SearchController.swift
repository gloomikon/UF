import UIKit

class SearchController: UIViewController {
    @IBOutlet weak var searchBtn: UIButton!
    @IBOutlet weak var searchField: UITextField!
    
    var apiSearchController: APISearchController?

    override func viewDidLoad() {
        super.viewDidLoad()
        apiSearchController = APISearchController(delegate: self)
        self.navigationItem.hidesBackButton = true
        searchBtn.layer.cornerRadius = 10
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
}
