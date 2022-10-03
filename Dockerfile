FROM gcc:12.2.0 as builder

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      cmake

COPY docker-entrypoint docker-entrypoint

ENTRYPOINT ["./docker-entrypoint"]
