
FROM archlinux:latest

RUN pacman -Sy --noconfirm \
          base-devel \
          cmake \
          git \
          ninja
