//
//  button.m
//  SUSTech_Helper
//
//  Created by 开心 on 2020/12/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface Button : UIViewController

@end
@implementation Button

- (IBAction)back:(UIBarButtonItem *)sender {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.edgesForExtendedLayout = UIRectEdgeNone;
}

@end
