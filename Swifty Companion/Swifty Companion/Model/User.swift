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
    let grade: String
    let level: Double
    let begin_at: Date
    let skills: [Skill]
    let projects: [Project]
}
