// INSKButton.h
//
// Copyright (c) 2014 Sven Korset
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import <SpriteKit/SpriteKit.h>


/**
 A button node for easy action handling.
 
 This class represents a button which can be enabled and disabled.
 The highlight state will be updated by the user's touch and correspondign selectors called.
 The INSKButton instance can also be used as a toggle button with it's selected state which will also be automatically updated.
 After initializing a new instance assign SKNode objects to the node properties.
 They will be added and removed automatically upon the state changes of the button.
 At least the nodeNormal and nodeHighlighted node should be set with a visual representation or the button will be invisible.
 The nodeDisabled is only used if the enabled flag is manually set to NO.
 nodeSelectedNormal and nodeSelectedHighlighted are only needed if the selected flag is also used.
 Register for target-action callbacks to get informed about user input.
 Call updateState after initializing to make the button visible.
 */
@interface INSKButton : SKSpriteNode

// ------------------------------------------------------------
#pragma mark - Properties
// ------------------------------------------------------------

/**
 Flag indicating whether the button is enabled. Defaults to YES.
 
 Disable the button manually according to the logic.
 If set to NO the nodeDisabled will be shown and user input ignored.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;


/**
 Flag indicationg whether the button is acutally pressed and thus highlighted.
 
 This flag automatically updates to the user input.
 If YES nodeHighlighted or nodeSelectedHighlighted will be shown.
 */
@property (nonatomic, assign, getter=isHighlighted) BOOL highlighted;


/**
 Flag indicating whether the toggle button is actually in the selected mode or not.
 
 Each touch lifting inside of the button will toggle this state automatically, but only if updateSelectedStateAutomatically is set to YES.
 If YES nodeSelectedNormal and nodeSelectedHighlighted will be used instead of nodeNormal and nodeHighlighted.
 @see updateSelectedStateAutomatically
 */
@property (nonatomic, assign, getter=isSelected) BOOL selected;


/**
 Activate to make the button automatically toggle its selected state. Defaults to NO.
 
 If set to YES the selected property will be updated automatically according to touch up events.
 */
@property (nonatomic, assign) BOOL updateSelectedStateAutomatically;

@property (nonatomic, strong) SKNode *nodeDisabled;
@property (nonatomic, strong) SKNode *nodeNormal;
@property (nonatomic, strong) SKNode *nodeHighlighted;
@property (nonatomic, strong) SKNode *nodeSelectedNormal;
@property (nonatomic, strong) SKNode *nodeSelectedHighlighted;


// ------------------------------------------------------------
#pragma mark - Initializer
// ------------------------------------------------------------

/**
 Creates and returns a new instance of INSKButton.
 
 Calls initWithSize:.
 
 @param size The size of the button.
 @return A new button instance.
 @see initWithSize:
 */
+ (INSKButton *)buttonNodeWithSize:(CGSize)size;


/**
 Initializes a INSKButton instance with the given size.
 
 The size describes the touch area of the button.
 An instance of INSKButton is also a SKSpriteNode so a background image or color may be set.
 However the button representation should be done with the other nodes the button contains of.
 
 @param size The size of the button.
 @return The initialized node.
 */
- (instancetype)initWithSize:(CGSize)size;


// ------------------------------------------------------------
#pragma mark - public methods
// ------------------------------------------------------------

/**
 Updates the visual representation of the button.
 
 All nodes are updating and adding to the tree as the states indicate.
 The method should be called after initializing and adding the corresponding node properties in order to make the button visible.
 @warning *This method should be called once after initializing.*
 */
- (void)updateState;


// ------------------------------------------------------------
#pragma mark - Target-action setter
// ------------------------------------------------------------

/**
 @name Seting the target-action pair.
 */

/**
 Target-action pair that is called when the touch goes up inside of the button's frame.
 
 @param target The target to invoce the action on. Will not be retained.
 @param action The action to call.
 */
- (void)setTouchUpInsideTarget:(id)target action:(SEL)action;


/**
 Target-action pair that is called when the touch goes down inside of the button's frame.
 
 @param target The target to invoce the action on. Will not be retained.
 @param action The action to call.
 */
- (void)setTouchDownTarget:(id)target action:(SEL)action;


/**
 Target-action pair that is called when the touch goes up inside or outside of the button's frame.

 @param target The target to invoce the action on. Will not be retained.
 @param action The action to call.
 */
- (void)setTouchUpTarget:(id)target action:(SEL)action;


@end