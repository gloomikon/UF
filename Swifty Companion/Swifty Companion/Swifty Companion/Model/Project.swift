//
//  Project.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/22/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import Foundation

struct Project {
    let name: String
    let status: String
    let validated: Bool?
    let mark: Int?
    
    var description: String {
        return """
        name: \(name)
        status: \(status)
        validated: \(String(describing: validated))
        mark: \(String(describing: mark))
        
        
        """
    }
}
