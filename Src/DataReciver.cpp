#include "../Includes/DataReciver.hpp"

DataReciver::DataReciver(byte recivers_name, byte senders_name)
: recivers_name(recivers_name),
senders_name(senders_name)
{
	seq_num = 0;
	file_number = 0;
}

int DataReciver::add_packet(Packet packet)
{
	if (packet.seq_num != seq_num)
	{
		int tmp_seq_num = seq_num;
		int tmp_packet_seq_num = packet.seq_num;
		if (abs(tmp_packet_seq_num - tmp_seq_num) >= 128)
		{
			if (tmp_seq_num < tmp_packet_seq_num)
				tmp_seq_num += 256;
			else
				tmp_packet_seq_num += 256;
		}
		i (tmp)
	}
	
	if (packet.data[0] == 0)
	{
		std::ofstream file("files/from " + std::to_string(senders_name) + " to " + std::to_string(recivers_name)
				+ std::to_string(file_number));
		file << recived_data;
		file_number++;
		recived_data = "";
		file.close();
		seq_num = 0;
		return packet.seq_num;
	}
}