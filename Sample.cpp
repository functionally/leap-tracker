/******************************************************************************\
* Copyright (C) 2012-2014 Leap Motion, Inc. All rights reserved.               *
* Leap Motion proprietary and confidential. Not for distribution.              *
* Use subject to the terms of the Leap Motion SDK Agreement available at       *
* https://developer.leapmotion.com/sdk_agreement, or another agreement         *
* between Leap Motion and you, your company or other organization.             *
\******************************************************************************/

#include <iostream>
#include <cstring>
#include "Leap.h"

using namespace Leap;

class SampleListener : public Listener {
  public:
    virtual void onFrame(const Controller&);

  private:
};

void SampleListener::onFrame(const Controller& controller) {
  // Get the most recent frame and report some basic information
  const Frame frame = controller.frame();
  const ImageList images = frame.images();
  if (images.count() == 0)
    return;
  for (int i = 0; i < 2; ++ i) {
    const Image image = images[i];
    const unsigned char* image_buffer = image.data();
    for (int j = 0; j < image.width() * image.height(); ++j)
      std::cout << i << " " << j << " " << (int) image_buffer[j] << std::endl;
  }
}

int main(int argc, char** argv) {
  SampleListener listener;
  Controller controller;

//controller.addListener(listener);

  if (argc > 1 && strcmp(argv[1], "--bg") == 0)
    controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);
  controller.setPolicy(Leap::Controller::POLICY_IMAGES);

  std::cout << "Press Enter to quit..." << std::endl;
  std::cin.get();
  listener.onFrame(controller);

//controller.removeListener(listener);

  return 0;
}
