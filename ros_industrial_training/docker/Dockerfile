# Docker image with all industrial training deps

FROM osrf/ros:kinetic-desktop-full
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

RUN apt-get update && apt-get install -y ros-kinetic-catkin python-catkin-tools \
                                         ros-kinetic-joint-state-publisher-gui \
                                         ros-kinetic-ur-description ros-kinetic-ur-kinematics 




ENTRYPOINT [ "/ros_entrypoint.sh" ]