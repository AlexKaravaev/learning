#XAUTH=/tmp/.docker.xauth
#XSOCK=/tmp/.X11-unix
#NV_GPU='0'
DOCKER_COMMON_ARGS="--gpus all --env=NVIDIA_VISIBLE_DEVICES=all --env=NVIDIA_DRIVER_CAPABILITIES=all --env=DISPLAY --env=QT_X11_NO_MITSHM=1 -v /tmp/.X11-unix:/tmp/.X11-unix:rw"

docker run -it \
        --net=host --privileged $DOCKER_COMMON_ARGS \
        -v $(pwd)/catkin_ws:/catkin_ws \
        --name ros_melodic --rm alexkaravaev/ros_melodic_gpu bash
