//
//  Skill.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/22/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import Foundation

struct Skill {
    let name: String
    let level: Double
    
    var description: String {
        return """
        name: \(name)
        level: \(level)
        
        
        """
    }
}
