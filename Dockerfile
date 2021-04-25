FROM storm2/build as builder

ADD --chown=build src /home/build/src
WORKDIR /home/build/src
RUN ./build.sh

FROM storm2/base
COPY --from=builder /home/build/src/build/memory_hog-0.1-Linux.tar.gz /
RUN tar xzvf /memory_hog-0.1-Linux.tar.gz --strip-component=1 && \
      echo /usr/local/lib > /etc/ld.so.conf.d/usrlocal.conf && \
      ldconfig && \
      rm /memory_hog-0.1-Linux.tar.gz

CMD memory_hog
