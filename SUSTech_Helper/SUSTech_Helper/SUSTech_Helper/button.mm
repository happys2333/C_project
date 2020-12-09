//
//  button.m
//  SUSTech_Helper
//
//  Created by 开心 on 2020/12/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "method.mm"
@interface Button : UIViewController
@property (strong, nonatomic) IBOutlet UILabel *sorce;
@property (strong, nonatomic) IBOutlet UIStepper *ad;
@property (nonatomic)
bool has;
@property (nonatomic)
int y;
@property (strong, nonatomic) IBOutlet
NSMutableArray* arrayOFlable;
@property (strong, nonatomic) IBOutlet
NSMutableArray* arrayOFsorce;
@property (strong, nonatomic) IBOutlet
NSMutableArray* arrayOFpercent;
@property (strong, nonatomic) IBOutlet UILabel *sigGPALable;

@end

@implementation Button

- (IBAction)back:(UIBarButtonItem *)sender {
    
    [self dismissModalViewControllerAnimated:YES];
    
}
- (IBAction)adder:(id)sender forEvent:(UIEvent *)event {
    int size = (int)_ad.value;
    int x=10,y=40;
    
    if(size==1 && !_has){
        _y = 50;
        _arrayOFsorce = [NSMutableArray arrayWithCapacity:1];
        _arrayOFpercent =[NSMutableArray arrayWithCapacity:1];
        _arrayOFlable =[NSMutableArray arrayWithCapacity:1];
        _has = true;
        _sorce.text = [[NSString alloc]initWithFormat:@"value = %d",size];
    }
    
    
}

- (IBAction)gpasi:(id)sender forEvent:(UIEvent *)event {
    int sorce =100;
    CGFloat totalGPA = 2;
    NSString * rank;
    if(totalGPA>4){
        rank = @"你不对劲!";
    }
    else if(totalGPA>3.5){
        rank = @"巨佬太强了";
    }
    else if(totalGPA>3){
        rank = @"大佬加油";
    }else if(totalGPA>1){
        rank = @"你GPA危";
    }else {
        rank = @"喜提重修";
    }
    _sigGPALable.text = [[NSString alloc] initWithFormat:@"您的总分为：%d 您的单科GPA为： %.2f %@",sorce, totalGPA,rank];
    
}






@end
