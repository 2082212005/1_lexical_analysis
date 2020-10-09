FROM codenvy/cpp_gcc
WORKDIR /app/
COPY ./* /app/
RUN chmod 777 main.cpp
RUN g++ main.cpp -o program -v
RUN chmod +x program