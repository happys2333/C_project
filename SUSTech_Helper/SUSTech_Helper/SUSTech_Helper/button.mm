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
@property (strong, nonatomic) IBOutlet UIView *GPAsigview;
@property (strong, nonatomic) IBOutlet UILabel *ranklabel;
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
/**
 16进制颜色转换为UIColor

 @param hexColor 16进制字符串（可以以0x开头，可以以#开头，也可以就是6位的16进制）
 @param opacity 透明度
 @return 16进制字符串对应的颜色
 */
+(UIColor *)colorWithHexString:(NSString *)hexColor alpha:(float)opacity{
    NSString * cString = [[hexColor stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];

    // String should be 6 or 8 characters
    if ([cString length] < 6) return [UIColor blackColor];

    // strip 0X if it appears
    if ([cString hasPrefix:@"0X"]) cString = [cString substringFromIndex:2];
    if ([cString hasPrefix:@"#"]) cString = [cString substringFromIndex:1];

    if ([cString length] != 6) return [UIColor blackColor];

    // Separate into r, g, b substrings
    NSRange range;
    range.location = 0;
    range.length = 2;
    NSString * rString = [cString substringWithRange:range];

    range.location = 2;
    NSString * gString = [cString substringWithRange:range];

    range.location = 4;
    NSString * bString = [cString substringWithRange:range];

    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];

    return [UIColor colorWithRed:((float)r / 255.0f)
                           green:((float)g / 255.0f)
                            blue:((float)b / 255.0f)
                           alpha:opacity];
}
- (IBAction)back:(UIBarButtonItem *)sender {
    
    [self dismissModalViewControllerAnimated:YES];
    
}
- (IBAction)adder:(id)sender forEvent:(UIEvent *)event {
    int size = (int)_ad.value;
    int sorce_x=30,precent_x=160,f_x=290,y=40,height =30,weight=75,yr=130;
    if(size==1 && !_has){
        _y = 50;
        _arrayOFsorce = [NSMutableArray arrayWithCapacity:1];
        _arrayOFpercent =[NSMutableArray arrayWithCapacity:1];
        _arrayOFlable =[NSMutableArray arrayWithCapacity:1];
        _has = true;
    }
        int nowsize = (int)_arrayOFlable.count;
        if(nowsize<size){
            /*
            * 增加一个
            */
            UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(f_x, y*size+yr, weight,height)];
            label.tag = 100+size;
            [_GPAsigview addSubview:label];
            [_arrayOFlable addObject:label];
            UITextField *sorce=[[UITextField alloc]initWithFrame:CGRectMake(sorce_x, y*size+yr, weight, height)];
            sorce.tag = 130+size;
            sorce.backgroundColor = [Button colorWithHexString:@"#CCCCCC" alpha:0.4];
            [_GPAsigview addSubview:sorce];
            [_arrayOFsorce addObject:sorce];
            UITextField *pre=[[UITextField alloc]init];
            pre.tag = 170+size;
            pre.frame = CGRectMake(precent_x, y*size+yr, weight,height);
            pre.backgroundColor =[Button colorWithHexString:@"#CCCCCC" alpha:0.4];
            [_GPAsigview addSubview:pre];
            [_arrayOFpercent addObject:pre];
            
        }else{
            /*
            * 减少一个
            */
            UIView *de;
            de = [_GPAsigview viewWithTag:100+nowsize];
            [de removeFromSuperview];
            [_arrayOFlable removeObjectAtIndex:(int)_arrayOFlable.count-1];
            de = [_GPAsigview viewWithTag:130+nowsize];
            [de removeFromSuperview];
            [_arrayOFsorce removeObjectAtIndex:(int)_arrayOFsorce.count-1];
            de = [_GPAsigview viewWithTag:170+nowsize];
            [de removeFromSuperview];
            [_arrayOFpercent removeObjectAtIndex:(int)_arrayOFpercent.count-1];
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
    _sigGPALable.text = [[NSString alloc] initWithFormat:@"您的总分为：%d 您的单科GPA为： %.2f",sorce, totalGPA];
    _ranklabel.text = rank;
}







@end
