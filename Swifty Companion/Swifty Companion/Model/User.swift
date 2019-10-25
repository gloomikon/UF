//
//  User.swift
//  Swifty Companion
//
//  Created by Mykola ZHURBA on 10/22/19.
//  Copyright © 2019 Mykola ZHURBA. All rights reserved.
//

import Foundation

struct User {
    let login: String
    let displayname: String
    let image_url: String
    let email: String
    let correction_point: Int
    let wallet: Int
    let grade: String?
    let level: Double
    let begin_at: Date
    let skills: [Skill]
    let projects: [Project]
    
    var description: String {
        var s =  """
        login: \(login)
        displayname: \(displayname)
        image_url" \(image_url)
        email: \(email)
        correction_point: \(correction_point)
        wallet: \(wallet)
        grade: \(String(describing: grade))
        level: \(level)
        begin_at: \(begin_at)
        
        
        """
        s = s + "skills:\n"
        for skill in skills {
            s = s + skill.description
        }
        s = s + "projects:\n"
        for project in projects {
            s = s + project.description
        }
        return s
    }
}
