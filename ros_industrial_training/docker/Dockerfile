# Docker image with all industrial training deps
#FROM osrf/ros:kinetic-desktop-full
FROM koenlek/ros-nvidia:kinetic-desktop-full

ENV LANG C.UTF-8

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections


# Docker image with all industrial training deps
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y ros-kinetic-catkin python-catkin-tools \
                                         ros-kinetic-joint-state-publisher-gui ros-kinetic-calibration-msgs \
                                         iputils-ping apt-transport-https ca-certificates exuberant-ctags \
                                         tmux vim git htop sudo curl wget gnupg2 \ 
                                         ros-kinetic-ur-description ros-kinetic-ur-kinematics \
                                         ros-kinetic-moveit \
                                         mesa-utils \
    




#ENTRYPOINT [ "/ros_entrypoint.sh" ]
