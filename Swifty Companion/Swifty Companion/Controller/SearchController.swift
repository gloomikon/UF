//
//  SearchController.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/22/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import UIKit

class SearchController: UIViewController {
    @IBOutlet weak var searchBtn: UIButton!
    @IBOutlet weak var searchField: UITextField!
    
    var apiController: APIController?

    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.hidesBackButton = true
        searchBtn.layer.cornerRadius = 10
    }
    
    @IBAction func search(_ sender: UIButton) {
        apiController?.getUserInfo(login: searchField.text!)
    }
}
