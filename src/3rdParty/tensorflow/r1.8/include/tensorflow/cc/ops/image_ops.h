// This file is MACHINE GENERATED! Do not edit.

#ifndef D__WORK_LIB_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_TENSORFLOW_CC_OPS_IMAGE_OPS_H_
#define D__WORK_LIB_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_TENSORFLOW_CC_OPS_IMAGE_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup image_ops Image Ops
/// @{

/// Adjust the contrast of one or more images.
///
/// `images` is a tensor of at least 3 dimensions.  The last 3 dimensions are
/// interpreted as `[height, width, channels]`.  The other dimensions only
/// represent a collection of images, such as `[batch, height, width, channels].`
/// 
/// Contrast is adjusted independently for each channel of each image.
/// 
/// For each channel, the Op first computes the mean of the image pixels in the
/// channel and then adjusts each component of each pixel to
/// `(x - mean) * contrast_factor + mean`.
///
/// Arguments:
/// * scope: A Scope object
/// * images: Images to adjust.  At least 3-D.
/// * contrast_factor: A float multiplier for adjusting contrast.
///
/// Returns:
/// * `Output`: The contrast-adjusted image or images.
class AdjustContrast {
 public:
  AdjustContrast(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
               ::tensorflow::Input contrast_factor);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// Adjust the hue of one or more images.
///
/// `images` is a tensor of at least 3 dimensions.  The last dimension is
/// interpretted as channels, and must be three.
/// 
/// The input image is considered in the RGB colorspace. Conceptually, the RGB
/// colors are first mapped into HSV. A delta is then applied all the hue values,
/// and then remapped back to RGB colorspace.
///
/// Arguments:
/// * scope: A Scope object
/// * images: Images to adjust.  At least 3-D.
/// * delta: A float delta to add to the hue.
///
/// Returns:
/// * `Output`: The hue-adjusted image or images.
class AdjustHue {
 public:
  AdjustHue(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
          ::tensorflow::Input delta);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// Adjust the saturation of one or more images.
///
/// `images` is a tensor of at least 3 dimensions.  The last dimension is
/// interpretted as channels, and must be three.
/// 
/// The input image is considered in the RGB colorspace. Conceptually, the RGB
/// colors are first mapped into HSV. A scale is then applied all the saturation
/// values, and then remapped back to RGB colorspace.
///
/// Arguments:
/// * scope: A Scope object
/// * images: Images to adjust.  At least 3-D.
/// * scale: A float scale to add to the saturation.
///
/// Returns:
/// * `Output`: The hue-adjusted image or images.
class AdjustSaturation {
 public:
  AdjustSaturation(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
                 ::tensorflow::Input scale);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// Extracts crops from the input image tensor and bilinearly resizes them (possibly
///
/// with aspect ratio change) to a common output size specified by `crop_size`. This
/// is more general than the `crop_to_bounding_box` op which extracts a fixed size
/// slice from the input image and does not allow resizing or aspect ratio change.
/// 
/// Returns a tensor with `crops` from the input `image` at positions defined at the
/// bounding box locations in `boxes`. The cropped boxes are all resized (with
/// bilinear interpolation) to a fixed `size = [crop_height, crop_width]`. The
/// result is a 4-D tensor `[num_boxes, crop_height, crop_width, depth]`. The
/// resizing is corner aligned. In particular, if `boxes = [[0, 0, 1, 1]]`, the
/// method will give identical results to using `tf.image.resize_bilinear()`
/// with `align_corners=True`.
///
/// Arguments:
/// * scope: A Scope object
/// * image: A 4-D tensor of shape `[batch, image_height, image_width, depth]`.
/// Both `image_height` and `image_width` need to be positive.
/// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
/// specifies the coordinates of a box in the `box_ind[i]` image and is specified
/// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
/// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
/// `[0, 1]` interval of normalized image height is mapped to
/// `[0, image_height - 1]` in image height coordinates. We do allow `y1` > `y2`, in
/// which case the sampled crop is an up-down flipped version of the original
/// image. The width dimension is treated similarly. Normalized coordinates
/// outside the `[0, 1]` range are allowed, in which case we use
/// `extrapolation_value` to extrapolate the input image values.
/// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
/// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
/// * crop_size: A 1-D tensor of 2 elements, `size = [crop_height, crop_width]`. All
/// cropped image patches are resized to this size. The aspect ratio of the image
/// content is not preserved. Both `crop_height` and `crop_width` need to be
/// positive.
///
/// Optional attributes (see `Attrs`):
/// * method: A string specifying the interpolation method. Only 'bilinear' is
/// supported for now.
/// * extrapolation_value: Value used for extrapolation, when applicable.
///
/// Returns:
/// * `Output`: A 4-D tensor of shape `[num_boxes, crop_height, crop_width, depth]`.
class CropAndResize {
 public:
  /// Optional attribute setters for CropAndResize
  struct Attrs {
    /// A string specifying the interpolation method. Only 'bilinear' is
    /// supported for now.
    ///
    /// Defaults to "bilinear"
    TF_MUST_USE_RESULT Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    /// Value used for extrapolation, when applicable.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs ExtrapolationValue(float x) {
      Attrs ret = *this;
      ret.extrapolation_value_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
    float extrapolation_value_ = 0.0f;
  };
  CropAndResize(const ::tensorflow::Scope& scope, ::tensorflow::Input image,
              ::tensorflow::Input boxes, ::tensorflow::Input box_ind,
              ::tensorflow::Input crop_size);
  CropAndResize(const ::tensorflow::Scope& scope, ::tensorflow::Input image,
              ::tensorflow::Input boxes, ::tensorflow::Input box_ind,
              ::tensorflow::Input crop_size, const CropAndResize::Attrs& attrs);
  operator ::tensorflow::Output() const { return crops; }
  operator ::tensorflow::Input() const { return crops; }
  ::tensorflow::Node* node() const { return crops.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }
  static Attrs ExtrapolationValue(float x) {
    return Attrs().ExtrapolationValue(x);
  }

  ::tensorflow::Output crops;
};

/// Computes the gradient of the crop_and_resize op wrt the input boxes tensor.
///
/// Arguments:
/// * scope: A Scope object
/// * grads: A 4-D tensor of shape `[num_boxes, crop_height, crop_width, depth]`.
/// * image: A 4-D tensor of shape `[batch, image_height, image_width, depth]`.
/// Both `image_height` and `image_width` need to be positive.
/// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
/// specifies the coordinates of a box in the `box_ind[i]` image and is specified
/// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
/// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
/// `[0, 1]` interval of normalized image height is mapped to
/// `[0, image_height - 1] in image height coordinates. We do allow y1 > y2, in
/// which case the sampled crop is an up-down flipped version of the original
/// image. The width dimension is treated similarly. Normalized coordinates
/// outside the `[0, 1]` range are allowed, in which case we use
/// `extrapolation_value` to extrapolate the input image values.
/// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
/// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
///
/// Optional attributes (see `Attrs`):
/// * method: A string specifying the interpolation method. Only 'bilinear' is
/// supported for now.
///
/// Returns:
/// * `Output`: A 2-D tensor of shape `[num_boxes, 4]`.
class CropAndResizeGradBoxes {
 public:
  /// Optional attribute setters for CropAndResizeGradBoxes
  struct Attrs {
    /// A string specifying the interpolation method. Only 'bilinear' is
    /// supported for now.
    ///
    /// Defaults to "bilinear"
    TF_MUST_USE_RESULT Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
  };
  CropAndResizeGradBoxes(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       grads, ::tensorflow::Input image, ::tensorflow::Input
                       boxes, ::tensorflow::Input box_ind);
  CropAndResizeGradBoxes(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       grads, ::tensorflow::Input image, ::tensorflow::Input
                       boxes, ::tensorflow::Input box_ind, const
                       CropAndResizeGradBoxes::Attrs& attrs);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }

  ::tensorflow::Output output;
};

/// Computes the gradient of the crop_and_resize op wrt the input image tensor.
///
/// Arguments:
/// * scope: A Scope object
/// * grads: A 4-D tensor of shape `[num_boxes, crop_height, crop_width, depth]`.
/// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
/// specifies the coordinates of a box in the `box_ind[i]` image and is specified
/// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
/// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
/// `[0, 1]` interval of normalized image height is mapped to
/// `[0, image_height - 1] in image height coordinates. We do allow y1 > y2, in
/// which case the sampled crop is an up-down flipped version of the original
/// image. The width dimension is treated similarly. Normalized coordinates
/// outside the `[0, 1]` range are allowed, in which case we use
/// `extrapolation_value` to extrapolate the input image values.
/// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
/// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
/// * image_size: A 1-D tensor with value `[batch, image_height, image_width, depth]`
/// containing the original image size. Both `image_height` and `image_width` need
/// to be positive.
///
/// Optional attributes (see `Attrs`):
/// * method: A string specifying the interpolation method. Only 'bilinear' is
/// supported for now.
///
/// Returns:
/// * `Output`: A 4-D tensor of shape `[batch, image_height, image_width, depth]`.
class CropAndResizeGradImage {
 public:
  /// Optional attribute setters for CropAndResizeGradImage
  struct Attrs {
    /// A string specifying the interpolation method. Only 'bilinear' is
    /// supported for now.
    ///
    /// Defaults to "bilinear"
    TF_MUST_USE_RESULT Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
  };
  CropAndResizeGradImage(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       grads, ::tensorflow::Input boxes, ::tensorflow::Input
                       box_ind, ::tensorflow::Input image_size, DataType T);
  CropAndResizeGradImage(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       grads, ::tensorflow::Input boxes, ::tensorflow::Input
                       box_ind, ::tensorflow::Input image_size, DataType T,
                       const CropAndResizeGradImage::Attrs& attrs);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }

  ::tensorflow::Output output;
};

/// Decode and Crop a JPEG-encoded image to a uint8 tensor.
///
/// The attr `channels` indicates the desired number of color channels for the
/// decoded image.
/// 
/// Accepted values are:
/// 
/// *   0: Use the number of channels in the JPEG-encoded image.
/// *   1: output a grayscale image.
/// *   3: output an RGB image.
/// 
/// If needed, the JPEG-encoded image is transformed to match the requested number
/// of color channels.
/// 
/// The attr `ratio` allows downscaling the image by an integer factor during
/// decoding.  Allowed values are: 1, 2, 4, and 8.  This is much faster than
/// downscaling the image later.
/// 
/// 
/// It is equivalent to a combination of decode and crop, but much faster by only
/// decoding partial jpeg image.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D.  The JPEG-encoded image.
/// * crop_window: 1-D.  The crop window: [crop_y, crop_x, crop_height, crop_width].
///
/// Optional attributes (see `Attrs`):
/// * channels: Number of color channels for the decoded image.
/// * ratio: Downscaling ratio.
/// * fancy_upscaling: If true use a slower but nicer upscaling of the
/// chroma planes (yuv420/422 only).
/// * try_recover_truncated: If true try to recover an image from truncated input.
/// * acceptable_fraction: The minimum required fraction of lines before a truncated
/// input is accepted.
/// * dct_method: string specifying a hint about the algorithm used for
/// decompression.  Defaults to "" which maps to a system-specific
/// default.  Currently valid values are ["INTEGER_FAST",
/// "INTEGER_ACCURATE"].  The hint may be ignored (e.g., the internal
/// jpeg library changes to a version that does not have that specific
/// option.)
///
/// Returns:
/// * `Output`: 3-D with shape `[height, width, channels]`..
class DecodeAndCropJpeg {
 public:
  /// Optional attribute setters for DecodeAndCropJpeg
  struct Attrs {
    /// Number of color channels for the decoded image.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    /// Downscaling ratio.
    ///
    /// Defaults to 1
    TF_MUST_USE_RESULT Attrs Ratio(int64 x) {
      Attrs ret = *this;
      ret.ratio_ = x;
      return ret;
    }

    /// If true use a slower but nicer upscaling of the
    /// chroma planes (yuv420/422 only).
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs FancyUpscaling(bool x) {
      Attrs ret = *this;
      ret.fancy_upscaling_ = x;
      return ret;
    }

    /// If true try to recover an image from truncated input.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs TryRecoverTruncated(bool x) {
      Attrs ret = *this;
      ret.try_recover_truncated_ = x;
      return ret;
    }

    /// The minimum required fraction of lines before a truncated
    /// input is accepted.
    ///
    /// Defaults to 1
    TF_MUST_USE_RESULT Attrs AcceptableFraction(float x) {
      Attrs ret = *this;
      ret.acceptable_fraction_ = x;
      return ret;
    }

    /// string specifying a hint about the algorithm used for
    /// decompression.  Defaults to "" which maps to a system-specific
    /// default.  Currently valid values are ["INTEGER_FAST",
    /// "INTEGER_ACCURATE"].  The hint may be ignored (e.g., the internal
    /// jpeg library changes to a version that does not have that specific
    /// option.)
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs DctMethod(StringPiece x) {
      Attrs ret = *this;
      ret.dct_method_ = x;
      return ret;
    }

    int64 channels_ = 0;
    int64 ratio_ = 1;
    bool fancy_upscaling_ = true;
    bool try_recover_truncated_ = false;
    float acceptable_fraction_ = 1.0f;
    StringPiece dct_method_ = "";
  };
  DecodeAndCropJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  contents, ::tensorflow::Input crop_window);
  DecodeAndCropJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  contents, ::tensorflow::Input crop_window, const
                  DecodeAndCropJpeg::Attrs& attrs);
  operator ::tensorflow::Output() const { return image; }
  operator ::tensorflow::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }
  static Attrs Ratio(int64 x) {
    return Attrs().Ratio(x);
  }
  static Attrs FancyUpscaling(bool x) {
    return Attrs().FancyUpscaling(x);
  }
  static Attrs TryRecoverTruncated(bool x) {
    return Attrs().TryRecoverTruncated(x);
  }
  static Attrs AcceptableFraction(float x) {
    return Attrs().AcceptableFraction(x);
  }
  static Attrs DctMethod(StringPiece x) {
    return Attrs().DctMethod(x);
  }

  ::tensorflow::Output image;
};

/// Decode the first frame of a BMP-encoded image to a uint8 tensor.
///
/// The attr `channels` indicates the desired number of color channels for the
/// decoded image.
/// 
/// Accepted values are:
/// 
/// *   0: Use the number of channels in the BMP-encoded image.
/// *   3: output an RGB image.
/// *   4: output an RGBA image.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D.  The BMP-encoded image.
///
/// Returns:
/// * `Output`: 3-D with shape `[height, width, channels]`. RGB order
class DecodeBmp {
 public:
  /// Optional attribute setters for DecodeBmp
  struct Attrs {
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    int64 channels_ = 0;
  };
  DecodeBmp(const ::tensorflow::Scope& scope, ::tensorflow::Input contents);
  DecodeBmp(const ::tensorflow::Scope& scope, ::tensorflow::Input contents, const
          DecodeBmp::Attrs& attrs);
  operator ::tensorflow::Output() const { return image; }
  operator ::tensorflow::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }

  ::tensorflow::Output image;
};

/// Decode the first frame of a GIF-encoded image to a uint8 tensor.
///
/// GIF with frame or transparency compression are not supported
/// convert animated GIF from compressed to uncompressed by:
/// 
///     convert $src.gif -coalesce $dst.gif
/// 
/// This op also supports decoding JPEGs and PNGs, though it is cleaner to use
/// `tf.image.decode_image`.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D.  The GIF-encoded image.
///
/// Returns:
/// * `Output`: 4-D with shape `[num_frames, height, width, 3]`. RGB order
class DecodeGif {
 public:
  DecodeGif(const ::tensorflow::Scope& scope, ::tensorflow::Input contents);
  operator ::tensorflow::Output() const { return image; }
  operator ::tensorflow::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  ::tensorflow::Output image;
};

/// Decode a JPEG-encoded image to a uint8 tensor.
///
/// The attr `channels` indicates the desired number of color channels for the
/// decoded image.
/// 
/// Accepted values are:
/// 
/// *   0: Use the number of channels in the JPEG-encoded image.
/// *   1: output a grayscale image.
/// *   3: output an RGB image.
/// 
/// If needed, the JPEG-encoded image is transformed to match the requested number
/// of color channels.
/// 
/// The attr `ratio` allows downscaling the image by an integer factor during
/// decoding.  Allowed values are: 1, 2, 4, and 8.  This is much faster than
/// downscaling the image later.
/// 
/// 
/// This op also supports decoding PNGs and non-animated GIFs since the interface is
/// the same, though it is cleaner to use `tf.image.decode_image`.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D.  The JPEG-encoded image.
///
/// Optional attributes (see `Attrs`):
/// * channels: Number of color channels for the decoded image.
/// * ratio: Downscaling ratio.
/// * fancy_upscaling: If true use a slower but nicer upscaling of the
/// chroma planes (yuv420/422 only).
/// * try_recover_truncated: If true try to recover an image from truncated input.
/// * acceptable_fraction: The minimum required fraction of lines before a truncated
/// input is accepted.
/// * dct_method: string specifying a hint about the algorithm used for
/// decompression.  Defaults to "" which maps to a system-specific
/// default.  Currently valid values are ["INTEGER_FAST",
/// "INTEGER_ACCURATE"].  The hint may be ignored (e.g., the internal
/// jpeg library changes to a version that does not have that specific
/// option.)
///
/// Returns:
/// * `Output`: 3-D with shape `[height, width, channels]`..
class DecodeJpeg {
 public:
  /// Optional attribute setters for DecodeJpeg
  struct Attrs {
    /// Number of color channels for the decoded image.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    /// Downscaling ratio.
    ///
    /// Defaults to 1
    TF_MUST_USE_RESULT Attrs Ratio(int64 x) {
      Attrs ret = *this;
      ret.ratio_ = x;
      return ret;
    }

    /// If true use a slower but nicer upscaling of the
    /// chroma planes (yuv420/422 only).
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs FancyUpscaling(bool x) {
      Attrs ret = *this;
      ret.fancy_upscaling_ = x;
      return ret;
    }

    /// If true try to recover an image from truncated input.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs TryRecoverTruncated(bool x) {
      Attrs ret = *this;
      ret.try_recover_truncated_ = x;
      return ret;
    }

    /// The minimum required fraction of lines before a truncated
    /// input is accepted.
    ///
    /// Defaults to 1
    TF_MUST_USE_RESULT Attrs AcceptableFraction(float x) {
      Attrs ret = *this;
      ret.acceptable_fraction_ = x;
      return ret;
    }

    /// string specifying a hint about the algorithm used for
    /// decompression.  Defaults to "" which maps to a system-specific
    /// default.  Currently valid values are ["INTEGER_FAST",
    /// "INTEGER_ACCURATE"].  The hint may be ignored (e.g., the internal
    /// jpeg library changes to a version that does not have that specific
    /// option.)
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs DctMethod(StringPiece x) {
      Attrs ret = *this;
      ret.dct_method_ = x;
      return ret;
    }

    int64 channels_ = 0;
    int64 ratio_ = 1;
    bool fancy_upscaling_ = true;
    bool try_recover_truncated_ = false;
    float acceptable_fraction_ = 1.0f;
    StringPiece dct_method_ = "";
  };
  DecodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input contents);
  DecodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input contents,
           const DecodeJpeg::Attrs& attrs);
  operator ::tensorflow::Output() const { return image; }
  operator ::tensorflow::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }
  static Attrs Ratio(int64 x) {
    return Attrs().Ratio(x);
  }
  static Attrs FancyUpscaling(bool x) {
    return Attrs().FancyUpscaling(x);
  }
  static Attrs TryRecoverTruncated(bool x) {
    return Attrs().TryRecoverTruncated(x);
  }
  static Attrs AcceptableFraction(float x) {
    return Attrs().AcceptableFraction(x);
  }
  static Attrs DctMethod(StringPiece x) {
    return Attrs().DctMethod(x);
  }

  ::tensorflow::Output image;
};

/// Decode a PNG-encoded image to a uint8 or uint16 tensor.
///
/// The attr `channels` indicates the desired number of color channels for the
/// decoded image.
/// 
/// Accepted values are:
/// 
/// *   0: Use the number of channels in the PNG-encoded image.
/// *   1: output a grayscale image.
/// *   3: output an RGB image.
/// *   4: output an RGBA image.
/// 
/// If needed, the PNG-encoded image is transformed to match the requested number
/// of color channels.
/// 
/// This op also supports decoding JPEGs and non-animated GIFs since the interface
/// is the same, though it is cleaner to use `tf.image.decode_image`.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D.  The PNG-encoded image.
///
/// Optional attributes (see `Attrs`):
/// * channels: Number of color channels for the decoded image.
///
/// Returns:
/// * `Output`: 3-D with shape `[height, width, channels]`.
class DecodePng {
 public:
  /// Optional attribute setters for DecodePng
  struct Attrs {
    /// Number of color channels for the decoded image.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    /// Defaults to DT_UINT8
    TF_MUST_USE_RESULT Attrs Dtype(DataType x) {
      Attrs ret = *this;
      ret.dtype_ = x;
      return ret;
    }

    int64 channels_ = 0;
    DataType dtype_ = DT_UINT8;
  };
  DecodePng(const ::tensorflow::Scope& scope, ::tensorflow::Input contents);
  DecodePng(const ::tensorflow::Scope& scope, ::tensorflow::Input contents, const
          DecodePng::Attrs& attrs);
  operator ::tensorflow::Output() const { return image; }
  operator ::tensorflow::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }
  static Attrs Dtype(DataType x) {
    return Attrs().Dtype(x);
  }

  ::tensorflow::Output image;
};

/// Draw bounding boxes on a batch of images.
///
/// Outputs a copy of `images` but draws on top of the pixels zero or more bounding
/// boxes specified by the locations in `boxes`. The coordinates of the each
/// bounding box in `boxes` are encoded as `[y_min, x_min, y_max, x_max]`. The
/// bounding box coordinates are floats in `[0.0, 1.0]` relative to the width and
/// height of the underlying image.
/// 
/// For example, if an image is 100 x 200 pixels (height x width) and the bounding
/// box is `[0.1, 0.2, 0.5, 0.9]`, the upper-left and bottom-right coordinates of
/// the bounding box will be `(40, 10)` to `(100, 50)` (in (x,y) coordinates).
/// 
/// Parts of the bounding box may fall outside the image.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, depth]`. A batch of images.
/// * boxes: 3-D with shape `[batch, num_bounding_boxes, 4]` containing bounding
/// boxes.
///
/// Returns:
/// * `Output`: 4-D with the same shape as `images`. The batch of input images with
/// bounding boxes drawn on the images.
class DrawBoundingBoxes {
 public:
  DrawBoundingBoxes(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
                  ::tensorflow::Input boxes);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// JPEG-encode an image.
///
/// `image` is a 3-D uint8 Tensor of shape `[height, width, channels]`.
/// 
/// The attr `format` can be used to override the color format of the encoded
/// output.  Values can be:
/// 
/// *   `''`: Use a default format based on the number of channels in the image.
/// *   `grayscale`: Output a grayscale JPEG image.  The `channels` dimension
///     of `image` must be 1.
/// *   `rgb`: Output an RGB JPEG image. The `channels` dimension
///     of `image` must be 3.
/// 
/// If `format` is not specified or is the empty string, a default format is picked
/// in function of the number of channels in `image`:
/// 
/// *   1: Output a grayscale image.
/// *   3: Output an RGB image.
///
/// Arguments:
/// * scope: A Scope object
/// * image: 3-D with shape `[height, width, channels]`.
///
/// Optional attributes (see `Attrs`):
/// * format: Per pixel image format.
/// * quality: Quality of the compression from 0 to 100 (higher is better and slower).
/// * progressive: If True, create a JPEG that loads progressively (coarse to fine).
/// * optimize_size: If True, spend CPU/RAM to reduce size with no quality change.
/// * chroma_downsampling: See http://en.wikipedia.org/wiki/Chroma_subsampling.
/// * density_unit: Unit used to specify `x_density` and `y_density`:
/// pixels per inch (`'in'`) or centimeter (`'cm'`).
/// * x_density: Horizontal pixels per density unit.
/// * y_density: Vertical pixels per density unit.
/// * xmp_metadata: If not empty, embed this XMP metadata in the image header.
///
/// Returns:
/// * `Output`: 0-D. JPEG-encoded image.
class EncodeJpeg {
 public:
  /// Optional attribute setters for EncodeJpeg
  struct Attrs {
    /// Per pixel image format.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Format(StringPiece x) {
      Attrs ret = *this;
      ret.format_ = x;
      return ret;
    }

    /// Quality of the compression from 0 to 100 (higher is better and slower).
    ///
    /// Defaults to 95
    TF_MUST_USE_RESULT Attrs Quality(int64 x) {
      Attrs ret = *this;
      ret.quality_ = x;
      return ret;
    }

    /// If True, create a JPEG that loads progressively (coarse to fine).
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs Progressive(bool x) {
      Attrs ret = *this;
      ret.progressive_ = x;
      return ret;
    }

    /// If True, spend CPU/RAM to reduce size with no quality change.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs OptimizeSize(bool x) {
      Attrs ret = *this;
      ret.optimize_size_ = x;
      return ret;
    }

    /// See http://en.wikipedia.org/wiki/Chroma_subsampling.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs ChromaDownsampling(bool x) {
      Attrs ret = *this;
      ret.chroma_downsampling_ = x;
      return ret;
    }

    /// Unit used to specify `x_density` and `y_density`:
    /// pixels per inch (`'in'`) or centimeter (`'cm'`).
    ///
    /// Defaults to "in"
    TF_MUST_USE_RESULT Attrs DensityUnit(StringPiece x) {
      Attrs ret = *this;
      ret.density_unit_ = x;
      return ret;
    }

    /// Horizontal pixels per density unit.
    ///
    /// Defaults to 300
    TF_MUST_USE_RESULT Attrs XDensity(int64 x) {
      Attrs ret = *this;
      ret.x_density_ = x;
      return ret;
    }

    /// Vertical pixels per density unit.
    ///
    /// Defaults to 300
    TF_MUST_USE_RESULT Attrs YDensity(int64 x) {
      Attrs ret = *this;
      ret.y_density_ = x;
      return ret;
    }

    /// If not empty, embed this XMP metadata in the image header.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs XmpMetadata(StringPiece x) {
      Attrs ret = *this;
      ret.xmp_metadata_ = x;
      return ret;
    }

    StringPiece format_ = "";
    int64 quality_ = 95;
    bool progressive_ = false;
    bool optimize_size_ = false;
    bool chroma_downsampling_ = true;
    StringPiece density_unit_ = "in";
    int64 x_density_ = 300;
    int64 y_density_ = 300;
    StringPiece xmp_metadata_ = "";
  };
  EncodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input image);
  EncodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::Input image, const
           EncodeJpeg::Attrs& attrs);
  operator ::tensorflow::Output() const { return contents; }
  operator ::tensorflow::Input() const { return contents; }
  ::tensorflow::Node* node() const { return contents.node(); }

  static Attrs Format(StringPiece x) {
    return Attrs().Format(x);
  }
  static Attrs Quality(int64 x) {
    return Attrs().Quality(x);
  }
  static Attrs Progressive(bool x) {
    return Attrs().Progressive(x);
  }
  static Attrs OptimizeSize(bool x) {
    return Attrs().OptimizeSize(x);
  }
  static Attrs ChromaDownsampling(bool x) {
    return Attrs().ChromaDownsampling(x);
  }
  static Attrs DensityUnit(StringPiece x) {
    return Attrs().DensityUnit(x);
  }
  static Attrs XDensity(int64 x) {
    return Attrs().XDensity(x);
  }
  static Attrs YDensity(int64 x) {
    return Attrs().YDensity(x);
  }
  static Attrs XmpMetadata(StringPiece x) {
    return Attrs().XmpMetadata(x);
  }

  ::tensorflow::Output contents;
};

/// PNG-encode an image.
///
/// `image` is a 3-D uint8 or uint16 Tensor of shape `[height, width, channels]`
/// where `channels` is:
/// 
/// *   1: for grayscale.
/// *   2: for grayscale + alpha.
/// *   3: for RGB.
/// *   4: for RGBA.
/// 
/// The ZLIB compression level, `compression`, can be -1 for the PNG-encoder
/// default or a value from 0 to 9.  9 is the highest compression level, generating
/// the smallest output, but is slower.
///
/// Arguments:
/// * scope: A Scope object
/// * image: 3-D with shape `[height, width, channels]`.
///
/// Optional attributes (see `Attrs`):
/// * compression: Compression level.
///
/// Returns:
/// * `Output`: 0-D. PNG-encoded image.
class EncodePng {
 public:
  /// Optional attribute setters for EncodePng
  struct Attrs {
    /// Compression level.
    ///
    /// Defaults to -1
    TF_MUST_USE_RESULT Attrs Compression(int64 x) {
      Attrs ret = *this;
      ret.compression_ = x;
      return ret;
    }

    int64 compression_ = -1;
  };
  EncodePng(const ::tensorflow::Scope& scope, ::tensorflow::Input image);
  EncodePng(const ::tensorflow::Scope& scope, ::tensorflow::Input image, const
          EncodePng::Attrs& attrs);
  operator ::tensorflow::Output() const { return contents; }
  operator ::tensorflow::Input() const { return contents; }
  ::tensorflow::Node* node() const { return contents.node(); }

  static Attrs Compression(int64 x) {
    return Attrs().Compression(x);
  }

  ::tensorflow::Output contents;
};

/// Extracts a glimpse from the input tensor.
///
/// Returns a set of windows called glimpses extracted at location
/// `offsets` from the input tensor. If the windows only partially
/// overlaps the inputs, the non overlapping areas will be filled with
/// random noise.
/// 
/// The result is a 4-D tensor of shape `[batch_size, glimpse_height,
/// glimpse_width, channels]`. The channels and batch dimensions are the
/// same as that of the input tensor. The height and width of the output
/// windows are specified in the `size` parameter.
/// 
/// The argument `normalized` and `centered` controls how the windows are built:
/// 
/// * If the coordinates are normalized but not centered, 0.0 and 1.0
///   correspond to the minimum and maximum of each height and width
///   dimension.
/// * If the coordinates are both normalized and centered, they range from
///   -1.0 to 1.0. The coordinates (-1.0, -1.0) correspond to the upper
///   left corner, the lower right corner is located at (1.0, 1.0) and the
///   center is at (0, 0).
/// * If the coordinates are not normalized they are interpreted as
///   numbers of pixels.
///
/// Arguments:
/// * scope: A Scope object
/// * input: A 4-D float tensor of shape `[batch_size, height, width, channels]`.
/// * size: A 1-D tensor of 2 elements containing the size of the glimpses
/// to extract.  The glimpse height must be specified first, following
/// by the glimpse width.
/// * offsets: A 2-D integer tensor of shape `[batch_size, 2]` containing
/// the y, x locations of the center of each window.
///
/// Optional attributes (see `Attrs`):
/// * centered: indicates if the offset coordinates are centered relative to
/// the image, in which case the (0, 0) offset is relative to the center
/// of the input images. If false, the (0,0) offset corresponds to the
/// upper left corner of the input images.
/// * normalized: indicates if the offset coordinates are normalized.
/// * uniform_noise: indicates if the noise should be generated using a
/// uniform distribution or a Gaussian distribution.
///
/// Returns:
/// * `Output`: A tensor representing the glimpses `[batch_size,
/// glimpse_height, glimpse_width, channels]`.
class ExtractGlimpse {
 public:
  /// Optional attribute setters for ExtractGlimpse
  struct Attrs {
    /// indicates if the offset coordinates are centered relative to
    /// the image, in which case the (0, 0) offset is relative to the center
    /// of the input images. If false, the (0,0) offset corresponds to the
    /// upper left corner of the input images.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs Centered(bool x) {
      Attrs ret = *this;
      ret.centered_ = x;
      return ret;
    }

    /// indicates if the offset coordinates are normalized.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs Normalized(bool x) {
      Attrs ret = *this;
      ret.normalized_ = x;
      return ret;
    }

    /// indicates if the noise should be generated using a
    /// uniform distribution or a Gaussian distribution.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs UniformNoise(bool x) {
      Attrs ret = *this;
      ret.uniform_noise_ = x;
      return ret;
    }

    bool centered_ = true;
    bool normalized_ = true;
    bool uniform_noise_ = true;
  };
  ExtractGlimpse(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
               ::tensorflow::Input size, ::tensorflow::Input offsets);
  ExtractGlimpse(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
               ::tensorflow::Input size, ::tensorflow::Input offsets, const
               ExtractGlimpse::Attrs& attrs);
  operator ::tensorflow::Output() const { return glimpse; }
  operator ::tensorflow::Input() const { return glimpse; }
  ::tensorflow::Node* node() const { return glimpse.node(); }

  static Attrs Centered(bool x) {
    return Attrs().Centered(x);
  }
  static Attrs Normalized(bool x) {
    return Attrs().Normalized(x);
  }
  static Attrs UniformNoise(bool x) {
    return Attrs().UniformNoise(x);
  }

  ::tensorflow::Output glimpse;
};

/// Extract the shape information of a JPEG-encoded image.
///
/// This op only parses the image header, so it is much faster than DecodeJpeg.
///
/// Arguments:
/// * scope: A Scope object
/// * contents: 0-D. The JPEG-encoded image.
///
/// Optional attributes (see `Attrs`):
/// * output_type: (Optional) The output type of the operation (int32 or int64).
/// Defaults to int32.
///
/// Returns:
/// * `Output`: 1-D. The image shape with format [height, width, channels].
class ExtractJpegShape {
 public:
  /// Optional attribute setters for ExtractJpegShape
  struct Attrs {
    /// (Optional) The output type of the operation (int32 or int64).
    /// Defaults to int32.
    ///
    /// Defaults to DT_INT32
    TF_MUST_USE_RESULT Attrs OutputType(DataType x) {
      Attrs ret = *this;
      ret.output_type_ = x;
      return ret;
    }

    DataType output_type_ = DT_INT32;
  };
  ExtractJpegShape(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 contents);
  ExtractJpegShape(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 contents, const ExtractJpegShape::Attrs& attrs);
  operator ::tensorflow::Output() const { return image_shape; }
  operator ::tensorflow::Input() const { return image_shape; }
  ::tensorflow::Node* node() const { return image_shape.node(); }

  static Attrs OutputType(DataType x) {
    return Attrs().OutputType(x);
  }

  ::tensorflow::Output image_shape;
};

/// Convert one or more images from HSV to RGB.
///
/// Outputs a tensor of the same shape as the `images` tensor, containing the RGB
/// value of the pixels. The output is only well defined if the value in `images`
/// are in `[0,1]`.
/// 
/// See `rgb_to_hsv` for a description of the HSV encoding.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 1-D or higher rank. HSV data to convert. Last dimension must be size 3.
///
/// Returns:
/// * `Output`: `images` converted to RGB.
class HSVToRGB {
 public:
  HSVToRGB(const ::tensorflow::Scope& scope, ::tensorflow::Input images);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// Greedily selects a subset of bounding boxes in descending order of score,
///
/// pruning away boxes that have high intersection-over-union (IOU) overlap
/// with previously selected boxes.  Bounding boxes are supplied as
/// [y1, x1, y2, x2], where (y1, x1) and (y2, x2) are the coordinates of any
/// diagonal pair of box corners and the coordinates can be provided as normalized
/// (i.e., lying in the interval [0, 1]) or absolute.  Note that this algorithm
/// is agnostic to where the origin is in the coordinate system.  Note that this
/// algorithm is invariant to orthogonal transformations and translations
/// of the coordinate system; thus translating or reflections of the coordinate
/// system result in the same boxes being selected by the algorithm.
/// The output of this operation is a set of integers indexing into the input
/// collection of bounding boxes representing the selected boxes.  The bounding
/// box coordinates corresponding to the selected indices can then be obtained
/// using the `tf.gather operation`.  For example:
///   selected_indices = tf.image.non_max_suppression(
///       boxes, scores, max_output_size, iou_threshold)
///   selected_boxes = tf.gather(boxes, selected_indices)
///
/// Arguments:
/// * scope: A Scope object
/// * boxes: A 2-D float tensor of shape `[num_boxes, 4]`.
/// * scores: A 1-D float tensor of shape `[num_boxes]` representing a single
/// score corresponding to each box (each row of boxes).
/// * max_output_size: A scalar integer tensor representing the maximum number of
/// boxes to be selected by non max suppression.
///
/// Optional attributes (see `Attrs`):
/// * iou_threshold: A float representing the threshold for deciding whether boxes
/// overlap too much with respect to IOU.
///
/// Returns:
/// * `Output`: A 1-D integer tensor of shape `[M]` representing the selected
/// indices from the boxes tensor, where `M <= max_output_size`.
class NonMaxSuppression {
 public:
  /// Optional attribute setters for NonMaxSuppression
  struct Attrs {
    /// A float representing the threshold for deciding whether boxes
    /// overlap too much with respect to IOU.
    ///
    /// Defaults to 0.5
    TF_MUST_USE_RESULT Attrs IouThreshold(float x) {
      Attrs ret = *this;
      ret.iou_threshold_ = x;
      return ret;
    }

    float iou_threshold_ = 0.5f;
  };
  NonMaxSuppression(const ::tensorflow::Scope& scope, ::tensorflow::Input boxes,
                  ::tensorflow::Input scores, ::tensorflow::Input
                  max_output_size);
  NonMaxSuppression(const ::tensorflow::Scope& scope, ::tensorflow::Input boxes,
                  ::tensorflow::Input scores, ::tensorflow::Input
                  max_output_size, const NonMaxSuppression::Attrs& attrs);
  operator ::tensorflow::Output() const { return selected_indices; }
  operator ::tensorflow::Input() const { return selected_indices; }
  ::tensorflow::Node* node() const { return selected_indices.node(); }

  static Attrs IouThreshold(float x) {
    return Attrs().IouThreshold(x);
  }

  ::tensorflow::Output selected_indices;
};

/// Greedily selects a subset of bounding boxes in descending order of score,
///
/// pruning away boxes that have high intersection-over-union (IOU) overlap
/// with previously selected boxes.  Bounding boxes are supplied as
/// [y1, x1, y2, x2], where (y1, x1) and (y2, x2) are the coordinates of any
/// diagonal pair of box corners and the coordinates can be provided as normalized
/// (i.e., lying in the interval [0, 1]) or absolute.  Note that this algorithm
/// is agnostic to where the origin is in the coordinate system.  Note that this
/// algorithm is invariant to orthogonal transformations and translations
/// of the coordinate system; thus translating or reflections of the coordinate
/// system result in the same boxes being selected by the algorithm.
/// 
/// The output of this operation is a set of integers indexing into the input
/// collection of bounding boxes representing the selected boxes.  The bounding
/// box coordinates corresponding to the selected indices can then be obtained
/// using the `tf.gather operation`.  For example:
/// 
///   selected_indices = tf.image.non_max_suppression_v2(
///       boxes, scores, max_output_size, iou_threshold)
///   selected_boxes = tf.gather(boxes, selected_indices)
///
/// Arguments:
/// * scope: A Scope object
/// * boxes: A 2-D float tensor of shape `[num_boxes, 4]`.
/// * scores: A 1-D float tensor of shape `[num_boxes]` representing a single
/// score corresponding to each box (each row of boxes).
/// * max_output_size: A scalar integer tensor representing the maximum number of
/// boxes to be selected by non max suppression.
/// * iou_threshold: A 0-D float tensor representing the threshold for deciding whether
/// boxes overlap too much with respect to IOU.
///
/// Returns:
/// * `Output`: A 1-D integer tensor of shape `[M]` representing the selected
/// indices from the boxes tensor, where `M <= max_output_size`.
class NonMaxSuppressionV2 {
 public:
  NonMaxSuppressionV2(const ::tensorflow::Scope& scope, ::tensorflow::Input
                    boxes, ::tensorflow::Input scores, ::tensorflow::Input
                    max_output_size, ::tensorflow::Input iou_threshold);
  operator ::tensorflow::Output() const { return selected_indices; }
  operator ::tensorflow::Input() const { return selected_indices; }
  ::tensorflow::Node* node() const { return selected_indices.node(); }

  ::tensorflow::Output selected_indices;
};

/// Resize quantized `images` to `size` using quantized bilinear interpolation.
///
/// Input images and output images must be quantized types.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, channels]`.
/// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
/// new size for the images.
///
/// Optional attributes (see `Attrs`):
/// * align_corners: If true, the centers of the 4 corner pixels of the input and output tensors are
/// aligned, preserving the values at the corner pixels. Defaults to false.
///
/// Returns:
/// * `Output` resized_images: 4-D with shape
/// `[batch, new_height, new_width, channels]`.
/// * `Output` out_min
/// * `Output` out_max
class QuantizedResizeBilinear {
 public:
  /// Optional attribute setters for QuantizedResizeBilinear
  struct Attrs {
    /// If true, the centers of the 4 corner pixels of the input and output tensors are
    /// aligned, preserving the values at the corner pixels. Defaults to false.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  QuantizedResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::Input
                        images, ::tensorflow::Input size, ::tensorflow::Input
                        min, ::tensorflow::Input max);
  QuantizedResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::Input
                        images, ::tensorflow::Input size, ::tensorflow::Input
                        min, ::tensorflow::Input max, const
                        QuantizedResizeBilinear::Attrs& attrs);

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::Output resized_images;
  ::tensorflow::Output out_min;
  ::tensorflow::Output out_max;
};

/// Converts one or more images from RGB to HSV.
///
/// Outputs a tensor of the same shape as the `images` tensor, containing the HSV
/// value of the pixels. The output is only well defined if the value in `images`
/// are in `[0,1]`.
/// 
/// `output[..., 0]` contains hue, `output[..., 1]` contains saturation, and
/// `output[..., 2]` contains value. All HSV values are in `[0,1]`. A hue of 0
/// corresponds to pure red, hue 1/3 is pure green, and 2/3 is pure blue.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 1-D or higher rank. RGB data to convert. Last dimension must be size 3.
///
/// Returns:
/// * `Output`: `images` converted to HSV.
class RGBToHSV {
 public:
  RGBToHSV(const ::tensorflow::Scope& scope, ::tensorflow::Input images);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// Resize `images` to `size` using area interpolation.
///
/// Input images can be of different types but output images are always float.
/// 
/// The range of pixel values for the output image might be slightly different
/// from the range for the input image because of limited numerical precision.
/// To guarantee an output range, for example `[0.0, 1.0]`, apply
/// `tf.clip_by_value` to the output.
/// 
/// Each output pixel is computed by first transforming the pixel's footprint into
/// the input tensor and then averaging the pixels that intersect the footprint. An
/// input pixel's contribution to the average is weighted by the fraction of its
/// area that intersects the footprint.  This is the same as OpenCV's INTER_AREA.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, channels]`.
/// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
/// new size for the images.
///
/// Optional attributes (see `Attrs`):
/// * align_corners: If true, the centers of the 4 corner pixels of the input and output tensors are
/// aligned, preserving the values at the corner pixels. Defaults to false.
///
/// Returns:
/// * `Output`: 4-D with shape
/// `[batch, new_height, new_width, channels]`.
class ResizeArea {
 public:
  /// Optional attribute setters for ResizeArea
  struct Attrs {
    /// If true, the centers of the 4 corner pixels of the input and output tensors are
    /// aligned, preserving the values at the corner pixels. Defaults to false.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeArea(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
           ::tensorflow::Input size);
  ResizeArea(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
           ::tensorflow::Input size, const ResizeArea::Attrs& attrs);
  operator ::tensorflow::Output() const { return resized_images; }
  operator ::tensorflow::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::Output resized_images;
};

/// Resize `images` to `size` using bicubic interpolation.
///
/// Input images can be of different types but output images are always float.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, channels]`.
/// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
/// new size for the images.
///
/// Optional attributes (see `Attrs`):
/// * align_corners: If true, the centers of the 4 corner pixels of the input and output tensors are
/// aligned, preserving the values at the corner pixels. Defaults to false.
///
/// Returns:
/// * `Output`: 4-D with shape
/// `[batch, new_height, new_width, channels]`.
class ResizeBicubic {
 public:
  /// Optional attribute setters for ResizeBicubic
  struct Attrs {
    /// If true, the centers of the 4 corner pixels of the input and output tensors are
    /// aligned, preserving the values at the corner pixels. Defaults to false.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeBicubic(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
              ::tensorflow::Input size);
  ResizeBicubic(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
              ::tensorflow::Input size, const ResizeBicubic::Attrs& attrs);
  operator ::tensorflow::Output() const { return resized_images; }
  operator ::tensorflow::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::Output resized_images;
};

/// Resize `images` to `size` using bilinear interpolation.
///
/// Input images can be of different types but output images are always float.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, channels]`.
/// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
/// new size for the images.
///
/// Optional attributes (see `Attrs`):
/// * align_corners: If true, the centers of the 4 corner pixels of the input and output tensors are
/// aligned, preserving the values at the corner pixels. Defaults to false.
///
/// Returns:
/// * `Output`: 4-D with shape
/// `[batch, new_height, new_width, channels]`.
class ResizeBilinear {
 public:
  /// Optional attribute setters for ResizeBilinear
  struct Attrs {
    /// If true, the centers of the 4 corner pixels of the input and output tensors are
    /// aligned, preserving the values at the corner pixels. Defaults to false.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
               ::tensorflow::Input size);
  ResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::Input images,
               ::tensorflow::Input size, const ResizeBilinear::Attrs& attrs);
  operator ::tensorflow::Output() const { return resized_images; }
  operator ::tensorflow::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::Output resized_images;
};

/// Resize `images` to `size` using nearest neighbor interpolation.
///
/// Arguments:
/// * scope: A Scope object
/// * images: 4-D with shape `[batch, height, width, channels]`.
/// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
/// new size for the images.
///
/// Optional attributes (see `Attrs`):
/// * align_corners: If true, the centers of the 4 corner pixels of the input and output tensors are
/// aligned, preserving the values at the corner pixels. Defaults to false.
///
/// Returns:
/// * `Output`: 4-D with shape
/// `[batch, new_height, new_width, channels]`.
class ResizeNearestNeighbor {
 public:
  /// Optional attribute setters for ResizeNearestNeighbor
  struct Attrs {
    /// If true, the centers of the 4 corner pixels of the input and output tensors are
    /// aligned, preserving the values at the corner pixels. Defaults to false.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeNearestNeighbor(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      images, ::tensorflow::Input size);
  ResizeNearestNeighbor(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      images, ::tensorflow::Input size, const
                      ResizeNearestNeighbor::Attrs& attrs);
  operator ::tensorflow::Output() const { return resized_images; }
  operator ::tensorflow::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::Output resized_images;
};

/// Generate a single randomly distorted bounding box for an image.
///
/// Bounding box annotations are often supplied in addition to ground-truth labels
/// in image recognition or object localization tasks. A common technique for
/// training such a system is to randomly distort an image while preserving
/// its content, i.e. *data augmentation*. This Op outputs a randomly distorted
/// localization of an object, i.e. bounding box, given an `image_size`,
/// `bounding_boxes` and a series of constraints.
/// 
/// The output of this Op is a single bounding box that may be used to crop the
/// original image. The output is returned as 3 tensors: `begin`, `size` and
/// `bboxes`. The first 2 tensors can be fed directly into `tf.slice` to crop the
/// image. The latter may be supplied to `tf.image.draw_bounding_boxes` to visualize
/// what the bounding box looks like.
/// 
/// Bounding boxes are supplied and returned as `[y_min, x_min, y_max, x_max]`. The
/// bounding box coordinates are floats in `[0.0, 1.0]` relative to the width and
/// height of the underlying image.
/// 
/// For example,
/// 
/// ```python
///     # Generate a single distorted bounding box.
///     begin, size, bbox_for_draw = tf.image.sample_distorted_bounding_box(
///         tf.shape(image),
///         bounding_boxes=bounding_boxes)
/// 
///     # Draw the bounding box in an image summary.
///     image_with_box = tf.image.draw_bounding_boxes(tf.expand_dims(image, 0),
///                                                   bbox_for_draw)
///     tf.summary.image('images_with_box', image_with_box)
/// 
///     # Employ the bounding box to distort the image.
///     distorted_image = tf.slice(image, begin, size)
/// ```
/// 
/// Note that if no bounding box information is available, setting
/// `use_image_if_no_bounding_boxes = true` will assume there is a single implicit
/// bounding box covering the whole image. If `use_image_if_no_bounding_boxes` is
/// false and no bounding boxes are supplied, an error is raised.
///
/// Arguments:
/// * scope: A Scope object
/// * image_size: 1-D, containing `[height, width, channels]`.
/// * bounding_boxes: 3-D with shape `[batch, N, 4]` describing the N bounding boxes
/// associated with the image.
///
/// Optional attributes (see `Attrs`):
/// * seed: If either `seed` or `seed2` are set to non-zero, the random number
/// generator is seeded by the given `seed`.  Otherwise, it is seeded by a random
/// seed.
/// * seed2: A second seed to avoid seed collision.
/// * min_object_covered: The cropped area of the image must contain at least this
/// fraction of any bounding box supplied. The value of this parameter should be
/// non-negative. In the case of 0, the cropped area does not need to overlap
/// any of the bounding boxes supplied.
/// * aspect_ratio_range: The cropped area of the image must have an aspect ratio =
/// width / height within this range.
/// * area_range: The cropped area of the image must contain a fraction of the
/// supplied image within in this range.
/// * max_attempts: Number of attempts at generating a cropped region of the image
/// of the specified constraints. After `max_attempts` failures, return the entire
/// image.
/// * use_image_if_no_bounding_boxes: Controls behavior if no bounding boxes supplied.
/// If true, assume an implicit bounding box covering the whole input. If false,
/// raise an error.
///
/// Returns:
/// * `Output` begin: 1-D, containing `[offset_height, offset_width, 0]`. Provide as input to
/// `tf.slice`.
/// * `Output` size: 1-D, containing `[target_height, target_width, -1]`. Provide as input to
/// `tf.slice`.
/// * `Output` bboxes: 3-D with shape `[1, 1, 4]` containing the distorted bounding box.
/// Provide as input to `tf.image.draw_bounding_boxes`.
class SampleDistortedBoundingBox {
 public:
  /// Optional attribute setters for SampleDistortedBoundingBox
  struct Attrs {
    /// If either `seed` or `seed2` are set to non-zero, the random number
    /// generator is seeded by the given `seed`.  Otherwise, it is seeded by a random
    /// seed.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    /// A second seed to avoid seed collision.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    /// The cropped area of the image must contain at least this
    /// fraction of any bounding box supplied. The value of this parameter should be
    /// non-negative. In the case of 0, the cropped area does not need to overlap
    /// any of the bounding boxes supplied.
    ///
    /// Defaults to 0.1
    TF_MUST_USE_RESULT Attrs MinObjectCovered(float x) {
      Attrs ret = *this;
      ret.min_object_covered_ = x;
      return ret;
    }

    /// The cropped area of the image must have an aspect ratio =
    /// width / height within this range.
    ///
    /// Defaults to [0.75, 1.33]
    TF_MUST_USE_RESULT Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.aspect_ratio_range_ = x;
      return ret;
    }

    /// The cropped area of the image must contain a fraction of the
    /// supplied image within in this range.
    ///
    /// Defaults to [0.05, 1]
    TF_MUST_USE_RESULT Attrs AreaRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.area_range_ = x;
      return ret;
    }

    /// Number of attempts at generating a cropped region of the image
    /// of the specified constraints. After `max_attempts` failures, return the entire
    /// image.
    ///
    /// Defaults to 100
    TF_MUST_USE_RESULT Attrs MaxAttempts(int64 x) {
      Attrs ret = *this;
      ret.max_attempts_ = x;
      return ret;
    }

    /// Controls behavior if no bounding boxes supplied.
    /// If true, assume an implicit bounding box covering the whole input. If false,
    /// raise an error.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs UseImageIfNoBoundingBoxes(bool x) {
      Attrs ret = *this;
      ret.use_image_if_no_bounding_boxes_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
    float min_object_covered_ = 0.1f;
    gtl::ArraySlice<float> aspect_ratio_range_ = {0.75f, 1.33f};
    gtl::ArraySlice<float> area_range_ = {0.05f, 1.0f};
    int64 max_attempts_ = 100;
    bool use_image_if_no_bounding_boxes_ = false;
  };
  SampleDistortedBoundingBox(const ::tensorflow::Scope& scope,
                           ::tensorflow::Input image_size, ::tensorflow::Input
                           bounding_boxes);
  SampleDistortedBoundingBox(const ::tensorflow::Scope& scope,
                           ::tensorflow::Input image_size, ::tensorflow::Input
                           bounding_boxes, const
                           SampleDistortedBoundingBox::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }
  static Attrs MinObjectCovered(float x) {
    return Attrs().MinObjectCovered(x);
  }
  static Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AspectRatioRange(x);
  }
  static Attrs AreaRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AreaRange(x);
  }
  static Attrs MaxAttempts(int64 x) {
    return Attrs().MaxAttempts(x);
  }
  static Attrs UseImageIfNoBoundingBoxes(bool x) {
    return Attrs().UseImageIfNoBoundingBoxes(x);
  }

  ::tensorflow::Output begin;
  ::tensorflow::Output size;
  ::tensorflow::Output bboxes;
};

/// Generate a single randomly distorted bounding box for an image.
///
/// Bounding box annotations are often supplied in addition to ground-truth labels
/// in image recognition or object localization tasks. A common technique for
/// training such a system is to randomly distort an image while preserving
/// its content, i.e. *data augmentation*. This Op outputs a randomly distorted
/// localization of an object, i.e. bounding box, given an `image_size`,
/// `bounding_boxes` and a series of constraints.
/// 
/// The output of this Op is a single bounding box that may be used to crop the
/// original image. The output is returned as 3 tensors: `begin`, `size` and
/// `bboxes`. The first 2 tensors can be fed directly into `tf.slice` to crop the
/// image. The latter may be supplied to `tf.image.draw_bounding_boxes` to visualize
/// what the bounding box looks like.
/// 
/// Bounding boxes are supplied and returned as `[y_min, x_min, y_max, x_max]`. The
/// bounding box coordinates are floats in `[0.0, 1.0]` relative to the width and
/// height of the underlying image.
/// 
/// For example,
/// 
/// ```python
///     # Generate a single distorted bounding box.
///     begin, size, bbox_for_draw = tf.image.sample_distorted_bounding_box(
///         tf.shape(image),
///         bounding_boxes=bounding_boxes)
/// 
///     # Draw the bounding box in an image summary.
///     image_with_box = tf.image.draw_bounding_boxes(tf.expand_dims(image, 0),
///                                                   bbox_for_draw)
///     tf.summary.image('images_with_box', image_with_box)
/// 
///     # Employ the bounding box to distort the image.
///     distorted_image = tf.slice(image, begin, size)
/// ```
/// 
/// Note that if no bounding box information is available, setting
/// `use_image_if_no_bounding_boxes = true` will assume there is a single implicit
/// bounding box covering the whole image. If `use_image_if_no_bounding_boxes` is
/// false and no bounding boxes are supplied, an error is raised.
///
/// Arguments:
/// * scope: A Scope object
/// * image_size: 1-D, containing `[height, width, channels]`.
/// * bounding_boxes: 3-D with shape `[batch, N, 4]` describing the N bounding boxes
/// associated with the image.
/// * min_object_covered: The cropped area of the image must contain at least this
/// fraction of any bounding box supplied. The value of this parameter should be
/// non-negative. In the case of 0, the cropped area does not need to overlap
/// any of the bounding boxes supplied.
///
/// Optional attributes (see `Attrs`):
/// * seed: If either `seed` or `seed2` are set to non-zero, the random number
/// generator is seeded by the given `seed`.  Otherwise, it is seeded by a random
/// seed.
/// * seed2: A second seed to avoid seed collision.
/// * aspect_ratio_range: The cropped area of the image must have an aspect ratio =
/// width / height within this range.
/// * area_range: The cropped area of the image must contain a fraction of the
/// supplied image within in this range.
/// * max_attempts: Number of attempts at generating a cropped region of the image
/// of the specified constraints. After `max_attempts` failures, return the entire
/// image.
/// * use_image_if_no_bounding_boxes: Controls behavior if no bounding boxes supplied.
/// If true, assume an implicit bounding box covering the whole input. If false,
/// raise an error.
///
/// Returns:
/// * `Output` begin: 1-D, containing `[offset_height, offset_width, 0]`. Provide as input to
/// `tf.slice`.
/// * `Output` size: 1-D, containing `[target_height, target_width, -1]`. Provide as input to
/// `tf.slice`.
/// * `Output` bboxes: 3-D with shape `[1, 1, 4]` containing the distorted bounding box.
/// Provide as input to `tf.image.draw_bounding_boxes`.
class SampleDistortedBoundingBoxV2 {
 public:
  /// Optional attribute setters for SampleDistortedBoundingBoxV2
  struct Attrs {
    /// If either `seed` or `seed2` are set to non-zero, the random number
    /// generator is seeded by the given `seed`.  Otherwise, it is seeded by a random
    /// seed.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    /// A second seed to avoid seed collision.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    /// The cropped area of the image must have an aspect ratio =
    /// width / height within this range.
    ///
    /// Defaults to [0.75, 1.33]
    TF_MUST_USE_RESULT Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.aspect_ratio_range_ = x;
      return ret;
    }

    /// The cropped area of the image must contain a fraction of the
    /// supplied image within in this range.
    ///
    /// Defaults to [0.05, 1]
    TF_MUST_USE_RESULT Attrs AreaRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.area_range_ = x;
      return ret;
    }

    /// Number of attempts at generating a cropped region of the image
    /// of the specified constraints. After `max_attempts` failures, return the entire
    /// image.
    ///
    /// Defaults to 100
    TF_MUST_USE_RESULT Attrs MaxAttempts(int64 x) {
      Attrs ret = *this;
      ret.max_attempts_ = x;
      return ret;
    }

    /// Controls behavior if no bounding boxes supplied.
    /// If true, assume an implicit bounding box covering the whole input. If false,
    /// raise an error.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs UseImageIfNoBoundingBoxes(bool x) {
      Attrs ret = *this;
      ret.use_image_if_no_bounding_boxes_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
    gtl::ArraySlice<float> aspect_ratio_range_ = {0.75f, 1.33f};
    gtl::ArraySlice<float> area_range_ = {0.05f, 1.0f};
    int64 max_attempts_ = 100;
    bool use_image_if_no_bounding_boxes_ = false;
  };
  SampleDistortedBoundingBoxV2(const ::tensorflow::Scope& scope,
                             ::tensorflow::Input image_size,
                             ::tensorflow::Input bounding_boxes,
                             ::tensorflow::Input min_object_covered);
  SampleDistortedBoundingBoxV2(const ::tensorflow::Scope& scope,
                             ::tensorflow::Input image_size,
                             ::tensorflow::Input bounding_boxes,
                             ::tensorflow::Input min_object_covered, const
                             SampleDistortedBoundingBoxV2::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }
  static Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AspectRatioRange(x);
  }
  static Attrs AreaRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AreaRange(x);
  }
  static Attrs MaxAttempts(int64 x) {
    return Attrs().MaxAttempts(x);
  }
  static Attrs UseImageIfNoBoundingBoxes(bool x) {
    return Attrs().UseImageIfNoBoundingBoxes(x);
  }

  ::tensorflow::Output begin;
  ::tensorflow::Output size;
  ::tensorflow::Output bboxes;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // D__WORK_LIB_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_TENSORFLOW_CC_OPS_IMAGE_OPS_H_
