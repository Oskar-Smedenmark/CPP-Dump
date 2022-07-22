#ifndef IQUEUE_H
#define IQUEUE_H

template <typename T>
class IQueue
{
	public:
		virtual ~IQueue() = 0 {};
		virtual void enqueue(const T& element) = 0;
		virtual T dequeue() = 0;
		virtual T peek() const = 0;
		virtual bool isEmpty() const = 0;
};

#endif