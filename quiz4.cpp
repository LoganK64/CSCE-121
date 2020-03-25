bool is_seated_at_table(party_goer_p pers_at_table, party_goer_p might_be_at_table)
{
	assert(pers_at_table != NULL);
	assert(might_be_at_table != NULL);
    party_goer_p next = pers_at_table;

    do {   
        if (next == NULL)
            return false;
        next = next->sitting_to_left;
        if(next == might_be_at_table)
        	return true;
    } while (next != pers_at_table);

    return false;
}