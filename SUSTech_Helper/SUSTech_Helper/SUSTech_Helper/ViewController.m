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
// close and open
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
}
- (IBAction)unwindSegue:(UIStoryboardSegue *)sender{
    NSLog(@"unwindSegue %@", sender);
}
-(void)viewWillDisappear:(BOOL)animated

{

   [super viewWillDisappear:animated];

   if ([self.navigationController respondsToSelector:@selector(interactivePopGestureRecognizer)]) {

       self.navigationController.interactivePopGestureRecognizer.enabled = YES;

   }

}

- (void)viewDidAppear:(BOOL)animated

{

   [super viewDidAppear:animated];

//禁用返回手势

   if ([self.navigationController respondsToSelector:@selector(interactivePopGestureRecognizer)])

       self.navigationController.interactivePopGestureRecognizer.enabled = NO;

}

// type your code here


@end
