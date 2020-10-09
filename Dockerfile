FROM codenvy/cpp_gcc
RUN  mkdir /
WORKDIR /
COPY ./* ./
RUN g++ main.cpp -o program
RUN chmod +x program