FROM codenvy/cpp_gcc
WORKDIR /app/
COPY ./* ./
ls -al
RUN g++ main.cpp -o program
RUN chmod +x program