
FROM archlinux:latest

RUN pacman -Sy --noconfirm \
          base-devel \
          cmake \
          gdb \
          git \
          ninja
