import UIKit

class BioController: UIViewController {
    @IBOutlet weak var stackView: UIStackView!
    @IBOutlet weak var photo: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        photo.layer.cornerRadius = 50
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
}
