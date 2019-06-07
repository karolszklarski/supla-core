FROM supla/supla-server:arm32v7

RUN git clone https://github.com/karolszklarski/supla-core.git /src \
    && cd /src/supla-server/Release && make all \
    && cp /src/supla-server/Release/supla-server /usr/local/bin \
    && rm -fr /src

COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf


