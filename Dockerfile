FROM gcc:latest as builder

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      cmake

WORKDIR /app/build
