//
//  ViewController.swift
//  Ex_iOS_CPP_Swift
//
//  Created by Augusto Sanson Cadini on 20/02/19.
//  Copyright © 2019 Augusto Sanson Cadini. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    // 1.
    let cb_sum : callback_sum_t = { result in
        print("Swift: cb_sum -> Result: \(result)")
    }
    
    // 2.
    @objc func printMsg(notf: Notification) {
        let content = notf.object! as! UnsafePointer<CChar>
        print("Swift: \(String(cString: content))")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        NotificationCenter.default.addObserver(self, selector: #selector(printMsg), name: NSNotification.Name(rawValue: "msgFromCpp"), object: nil)
        
        // Simple call function on C++ code
        printFromCPP()
        
        // * 1
        
        // Setting up callback function throught function's pointer
        setCallbackSum(cb_sum)
        
        // Calling sumSimple function
        print("Swift: calling on C++ sumSimple: ")
        print("Swift: \(sumSimple(5.1, 12.5))") // Result on return
        
        // Calling sumCallback function
        print("Swift: calling on C++ sumCallback: ")
        sumCallback(12, 4) // Result on cb_sum callback
        
        // * 2
        
        // Setting up callback function throught function's pointer on struct
        var callbacks = StructCallbacks (
            deliveryToSwift: { (msg) in
                // Must use NotificationCenter to call function of this context
                NotificationCenter.default.post(name: Notification.Name(rawValue: "msgFromCpp"), object: msg)
            }
        )
        
        // Setting up function's pointer
        SetupStructCallback(&callbacks)
        
        // Call function to test
        invokeSwiftFunctionFromCpp()
        
        print("Swift: end")                
    }
    
}
