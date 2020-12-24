XAUTH=/tmp/.docker.xauth
XSOCK=/tmp/.X11-unix
NV_GPU='0' nvidia-docker run -it \
        -v $XSOCK:$XSOCK:rw \
        -v $XAUTH:$XAUTH:rw \
        -e XAUTHORITY=${XAUTH} \
        -e DISPLAY \
        --shm-size=1g \
        --ulimit memlock=-1 \
        --network=host \
        --privileged \
        -it -v $(pwd)/catkin_ws:/catkin_ws \
        --name ros_melodic --rm alexkaravaev/ros_melodic_gpu /bin/bash
