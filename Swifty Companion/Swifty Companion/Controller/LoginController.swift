//
//  ViewController.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/21/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import UIKit


class LoginController: UIViewController {
    @IBOutlet weak var connectBtn: UIButton!
    
    var apiController: APIController?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        apiController = APIController(delegate: self)
        connectBtn.layer.cornerRadius = 10
    }


    @IBAction func connect(_ sender: UIButton) {
        apiController?.getToken()
    }
    
    public func gotoSearchController() {
        let searchViewController = self.storyboard?.instantiateViewController(withIdentifier: "search") as! SearchController
        searchViewController.apiController = self.apiController
        self.navigationController!.pushViewController(searchViewController, animated: true)
    }
    
}

