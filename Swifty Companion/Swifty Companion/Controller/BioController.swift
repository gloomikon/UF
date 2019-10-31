import UIKit

class BioController: UIViewController {
    @IBOutlet weak var levelProgress: UIProgressView!
    @IBOutlet weak var levelText: UILabel!
    @IBOutlet weak var stackView: UIStackView!
    @IBOutlet weak var photo: UIImageView!
    @IBOutlet weak var displayname: UILabel!
    @IBOutlet weak var login: UILabel!
    
    let layer = CAGradientLayer()
    override func viewDidLoad() {
        super.viewDidLoad()
        photo.layer.cornerRadius = 75

        //levelProgress.transform = levelProgress.transform.scaledBy(x: 1, y: 50)
        levelText.text = String(format: "%.2f", serverData.user!.level)
        levelProgress.progress = Float(serverData.user!.level - floor(serverData.user!.level))
        levelProgress.layer.cornerRadius = 10
        levelProgress.clipsToBounds = true

        displayname.text = serverData.user?.displayname
        login.text = serverData.user?.login

        layer.frame = view.bounds
        layer.colors = [UIColor.cyan.cgColor, UIColor(red: 33/255, green: 33/255, blue: 117/255, alpha: 1).cgColor, UIColor.purple.cgColor]
        view.layer.insertSublayer(layer, at: 0)


        if UIDevice.current.orientation.isLandscape {
            stackView.axis = .horizontal
        } else {
            stackView.axis = .vertical
        }
        let url = URL(string: serverData.user!.image_url)
        URLSession.shared.dataTask(with: url!) {
            (data, resp, err) in
            guard let data = data, err == nil else { return }
            DispatchQueue.main.async {
                self.photo.image = UIImage(data: data)
            }
        }.resume()
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        if UIDevice.current.orientation.isLandscape {
            stackView.axis = .horizontal
        } else {
            stackView.axis = .vertical
        }
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        layer.frame = view.bounds
    }
}
