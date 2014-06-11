#include "Layer.h"


Layer::Layer()
{
}

Layer::Layer(std::vector<Neuron> neurons)
{
	m_Neurons = neurons;
}

Layer::~Layer()
{
}

std::vector<Neuron> Layer::GetNeurons()
{
	return m_Neurons;
}

Neuron Layer::GetNeuronAt(int index)
{
	return m_Neurons[index - 1];
}

void Layer::FireNeuronAt(int index, float sum)
{
	m_Neurons[index - 1].SetValue(m_Neurons[index - 1].FireSynapse(sum));
}

void Layer::FireInverseNeuronAt(int index, float sum)
{
	m_Neurons[index - 1].SetValue(m_Neurons[index - 1].FireInverseSynapse(sum));
}

void Layer::IncrementParentWeightAt(int index, float amount)
{
	m_Neurons[index - 1].IncrementParentWeight(amount);
}

void Layer::AddNeuron(Neuron newNeuron)
{
	m_Neurons.push_back(newNeuron);
}

Layer Layer::operator-(Layer other)
{
	for (unsigned int i = 1; i < other.GetNeurons().size(); ++i)
		m_Neurons[i - 1] = m_Neurons[i - 1] - other.GetNeuronAt(i);
	return *this;
}

bool Layer::operator==(Layer other)
{
	for (unsigned int i = 1; i < other.GetNeurons().size(); ++i)
		if (m_Neurons[i - 1].GetValue() != other.GetNeuronAt(i).GetValue())
			return false;
	return true;
}