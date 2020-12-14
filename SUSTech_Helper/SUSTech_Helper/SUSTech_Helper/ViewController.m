//
//  ViewController.m
//  SUSTech_Helper
//
//  Created by 开心 on 2020/11/25.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
- (IBAction)exitout:(id)sender forEvent:(UIEvent *)event {
    [self dismissModalViewControllerAnimated:YES];
}
- (IBAction)web:(id)sender {
    NSURL *URL = [NSURL URLWithString:@"https://www.sustech.edu.cn/zh/academic-calendar.html"];
    [[UIApplication sharedApplication]openURL:URL options:@{} completionHandler:^(BOOL success) {
    }];
}

// close and open






@end
