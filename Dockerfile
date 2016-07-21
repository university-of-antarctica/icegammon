FROM ubuntu:15.04
MAINTAINER gpwclark

# Update phusion and install necessary programs
RUN apt-get update && apt-get install -y \
  wget \
  libssl-dev \
  curl \
  ca-certificates \
  wamerican \
  build-essential \
  libreadline-dev \
  tmux \
  vim \
  cmake

# Make non sudo user and copy code from git repo to the docker image
 RUN useradd -ms /bin/bash user
RUN mkdir -p /home/user/app
ADD . /home/user/app

# Install lein
WORKDIR /home/user/app
RUN wget https://github.com/google/googletest/archive/release-1.7.0.tar.gz
RUN tar xf release-1.7.0.tar.gz
WORKDIR googletest-release-1.7.0
RUN cmake -DBUILD_SHARED_LIBS=ON .
RUN make
RUN cp -a include/gtest /usr/include
RUN cp -a libgtest_main.so libgtest.so /usr/lib/
WORKDIR /home/user/app
RUN helper_scripts/gtest_test_install.sh

# Housekeeping
RUN chown -R user:user /home/user
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
