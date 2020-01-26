//
//  SkillsTableViewCell.swift
//  Swifty Companion
//
//  Created by Nikolay Zhurba on 1/18/20.
//  Copyright © 2020 Mykola ZHURBA. All rights reserved.
//

import UIKit

class SkillsTableViewCell: UITableViewCell {
    @IBOutlet weak var nameLbl: UILabel!
    @IBOutlet weak var markLbl: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }

}
