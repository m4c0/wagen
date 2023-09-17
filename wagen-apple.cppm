export module wagen:apple;

#ifdef LECO_TARGET_IPHONEOS
#define MOLTEN "MoltenVK.xcframework/ios-arm64/libMoltenVK.a"
#pragma leco add_framework UIKit
#elif LECO_TARGET_IPHONESIMULATOR
#define MOLTEN "MoltenVK.xcframework/ios-arm64_x86_64-simulator/libMoltenVK.a"
#pragma leco add_framework UIKit
#elif LECO_TARGET_MACOSX
#define MOLTEN "MoltenVK.xcframework/macos-arm64_x86_64/libMoltenVK.a"
#pragma leco add_framework AppKit
#endif

#ifdef LECO_TARGET_APPLE
#pragma leco add_object MOLTEN
#pragma leco add_framework CoreFoundation CoreGraphics Foundation IOKit        \
    IOSurface MetalKit Metal QuartzCore
#endif
