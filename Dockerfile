FROM codenvy/cpp_gcc
WORKDIR /
COPY ./* ./
RUN g++ main.cpp -o program
RUN chmod +x program