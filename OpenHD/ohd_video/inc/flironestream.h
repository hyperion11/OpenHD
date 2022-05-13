#ifndef FLIRONESTREAM_H
#define FLIRONESTREAM_H

#include <array>
#include <stdexcept>
#include <vector>

#include "openhd-camera.hpp"
#include "openhd-platform.hpp"

#include "camerastream.h"

#include <gst/gst.h>

// Implementation of OHD CameraStream for Flir One. Untested.

class FlirOneStream: public CameraStream {
public:
    FlirOneStream(PlatformType platform, Camera camera, uint16_t port);

    void setup() override;

    void start() override;
    void stop() override;

    bool supports_bitrate() override;
    void set_bitrate(int bitrate) override;

    bool supports_cbr() override;
    void set_cbr(bool enable) override;

    std::vector<std::string> get_supported_formats() override;
    std::string get_format() override;
    void set_format(std::string format) override;
};

#endif
