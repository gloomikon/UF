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
    private let delegate: ViewController
    private var token: String?
    
    private let UID = "aca421ef55db61a13306c1ba22113fe9d3048a84b61a3d01c376c1fc4dca64e7"
    private let SECRET = "78aa60be8b774f7d9b98f56e4678c3e2d65e3db2c6aa2b169cd0d74c2c0eb378"
    private let siteUrl = "kolumbia://kolumbia"
    
    private var auth: ASWebAuthenticationSession?
    
    init(delegate: ViewController) {
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
                        print("Error")
                        return
                    }
                    do {
                        if let dict: NSDictionary = try JSONSerialization.jsonObject(with: data!) as? NSDictionary {
                            print(dict)
                            self.token = dict["access_token"] as? String
                            print(self.token)
                            //global_token.token = self.token
                        }
                        else {
                            print("error")
                        }
                    }
                    catch {
                        print("Error 2")
                    }
                    }.resume()
            }
        }
        auth?.start()
    }
}
