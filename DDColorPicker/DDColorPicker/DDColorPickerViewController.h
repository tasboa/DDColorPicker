//
//  DDColorPickerViewController.h
//  DDColorPicker
//
//  Created by Vasco d'Orey on 03/12/13.
//  Copyright (c) 2013 Delta Dog Studios. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(uint32_t, DDColorPickerOptions)
{
  DDColorPickerOptionsShowAlpha = (1 << 0),
  DDColorPickerOptionsShowLightness = (1 << 1),
  DDColorPickerOptionsDefault = DDColorPickerOptionsShowAlpha | DDColorPickerOptionsShowLightness
};

@protocol DDColorPicking;

/**
 *  Color picking view controller. Presents a color wheel, alpha & hue sliders.
 */
@interface DDColorPickerViewController : UIViewController

/**
 *  The delegate to the view controller. Set this property if you wish to be notified of the user's interactions.
 */
@property (nonatomic, weak) id <DDColorPicking> delegate;

/**
 *  Creates a new color picker
 */
+ (instancetype)colorPicker;

/**
 *  Creates a new color picker with the given delegate
 */
+ (instancetype)colorPickerWithDelegate:(id <DDColorPicking>)delegate;

/**
 *  Creates a new color picker with the given delegate and options
 */
+ (instancetype)colorPickerWithDelegate:(id <DDColorPicking>)delegate options:(DDColorPickerOptions)options;

@end

/**
 *  Color picking protocol. All methods are optional.
 */
@protocol DDColorPicking <NSObject>

@required

/**
 *  Sent to the delegate when the user specifically selected the given color.
 *
 *  @param viewController The sender instance
 *  @param color          The selected color
 */
- (void)colorPicker:(DDColorPickerViewController *)viewController didPickColor:(UIColor *)color;

@optional

/**
 *  Sent to the delegate when the specified color has been highlighted (i.e. the user swiped over the color).
 *
 *  @param viewController The sender instance
 *  @param color          The highlighted color
 */
- (void)colorPicker:(DDColorPickerViewController *)viewController didHighlightColor:(UIColor *)color;

@end
