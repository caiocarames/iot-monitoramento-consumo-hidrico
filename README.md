# Sistema Inteligente de Monitoramento de Consumo Hídrico com IoT

Projeto acadêmico desenvolvido na Universidade Presbiteriana Mackenzie com foco em sustentabilidade e IoT. Utiliza ESP32, sensor de fluxo de água, protocolo MQTT, Node-RED e dashboards no Grafana.

## Descrição

O sistema monitora o consumo de água em tempo real, integrando sensores com um ambiente de programação visual (Node-RED), banco de dados (InfluxDB ou CSV) e visualizações em dashboards interativos.

Este projeto está alinhado com o Objetivo de Desenvolvimento Sustentável 6 da ONU.

## Componentes

- **ESP32** com código em C++ para leitura de sensor de fluxo
- **Node-RED** para orquestração de dados MQTT
- **OpenWeather API** para dados climáticos
- **Grafana** com dados simulados em CSV

## Organização dos arquivos

- `/dispositivo-esp32`: código `.ino` do ESP32
- `/node-red`: exportação do fluxo visual em `.json`
- `/imagens`: imagens ilustrativas e esquemas
- `/dados-simulados`: arquivos `.csv` usados no Grafana
- `/dashboards`: dashboard `.json` para importar no Grafana

## Tecnologias utilizadas

- ESP32
- Sensor de fluxo de água YF-S201
- MQTT (Mosquitto Broker)
- Node-RED
- Grafana
- OpenWeatherMap API

## Desenvolvedores

- Caio Caramês  
- Lucca Pivoto  

