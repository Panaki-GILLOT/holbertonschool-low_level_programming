#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *node;
    hash_node_t *tmp;
    char *value_copy;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            value_copy = strdup(value);
            if (value_copy == NULL)
                return (0);

            free(tmp->value);
            tmp->value = value_copy;
            return (1);
        }
        tmp = tmp->next;
    }

    node = malloc(sizeof(hash_node_t));
    if (node == NULL)
        return (0);

    node->key = strdup(key);
    node->value = strdup(value);

    if (node->key == NULL || node->value == NULL)
    {
        free(node->key);
        free(node->value);
        free(node);
        return (0);
    }

    node->next = ht->array[index];
    ht->array[index] = node;

    return (1);
}