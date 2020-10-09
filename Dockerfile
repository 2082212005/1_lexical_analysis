FROM codenvy/cpp_gcc
WORKDIR /app/
COPY ./* /app/
RUN g++ main.cpp -o program
RUN chmod +x program