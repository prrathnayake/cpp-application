#include <iostream>

#include <kafka/index.h>
#include <utils/index.h>

void receiveMessage(kafka::KafkaConsumer *kafkaConsumer)
{
    kafka::ExCosumeCb cb;
    kafkaConsumer->consumeMessages(cb);
}

void sendMessage(kafka::KafkaProducer *kafkaProducer)
{
    int count = 0;
    while (count < 10)
    {
        kafkaProducer->produceMessages("topic", "message");
        count++;
    }
}

int main()
{
    utils::ThreadPool pool;
    pool.addThread("consumer");
    pool.addThread("producer");

    kafka::KafkaConsumer *kafkaConsumer = new kafka::KafkaConsumer("localhost:9092", "topic");
    pool.addTask("consumer", std::bind(receiveMessage, kafkaConsumer));

    kafka::KafkaProducer *kafkaProducer = new kafka::KafkaProducer("localhost:9092");
    pool.addTask("producer", std::bind(sendMessage, kafkaProducer));

    int input;
    std::cin >> input;
    kafkaConsumer->stopConsumeMessages();
    delete kafkaProducer;
    delete kafkaConsumer;

    std::cout << "End" << std::endl;

    pool.joinAll();

    return 0;
}