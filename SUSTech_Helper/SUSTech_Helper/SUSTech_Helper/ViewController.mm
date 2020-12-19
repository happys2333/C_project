//
//  ViewController.m
//  SUSTech_Helper
//
//  Created by 开心 on 2020/11/25.
//

#import "ViewController.h"
#import <WebKit/WKWebView.h>
@interface ViewController ()
@property (weak, nonatomic) IBOutlet WKWebView *WebPage;
@end

@implementation ViewController
- (IBAction)exitout:(id)sender forEvent:(UIEvent *)event {
    [self dismissModalViewControllerAnimated:YES];
}
- (IBAction)web:(id)sender {
    NSURL *URL = [NSURL URLWithString:@"https://www.sustech.edu.cn/zh/academic-calendar.html"];
    [_WebPage loadRequest:[NSURLRequest requestWithURL:URL]];
}

// close and open






@end
