FROM g++
WORKDIR /app/
COPY ./
RUN g++ main.cpp -o program
RUN chmod +x program