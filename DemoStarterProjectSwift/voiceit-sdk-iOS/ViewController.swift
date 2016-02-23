//
//  ViewController.swift
//  voiceit-sdk-iOS
//
//  Created by Armaan Bindra on 8/28/15.
//  Copyright (c) 2015 VoiceIt Technologies LLC. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    //ADD YOUR VOICEIT DEVELOPER ID HERE for Example: 123456, If you do not already have a DEVELOPER ID get one 
    //at https://siv.voiceprintportal.com/getDeveloperID.jsp
    
    let DEVELOPER_ID = "196468c9b5a24345afe5ea2878ac6f0f"

    @IBOutlet weak var userTokenField: UITextField!
    @IBOutlet weak var resultLabel: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func loginClicked(sender: AnyObject) {
        let vc = VoiceItLogin(DEVELOPER_ID,userToken: userTokenField.text!,vpPhrase: "M�s vale p�jaro en mano que cien volando.", textConfidence: "30.0", confidence: "89" , contentLanguage: "es-ES", callback: { (result) -> Void in
            print("Result is \(result)");
            if result == "Success"
            {
                self.resultLabel.text = "Login Success";
            }
            else if result == "Failed"
            {
                self.resultLabel.text = "Login Failed";
            }
            
        })
        self.presentViewController(vc, animated: true, completion: nil)
    }


}

