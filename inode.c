#include "allocation.h"
#include "inode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLOCKSIZE 4096

//global rotnode
struct inode *rotnode = NULL;

///ttredje som må gjøre 
struct inode* create_file( struct inode* parent, char* name, char readonly, int size_in_bytes )
{

    return NULL;
}
//lager bare en struct på måten man gjør i oppgaver jeg har linket til.
struct inode* create_dir( struct inode* parent, char* name )
{
    struct inode *in = malloc(sizeof(struct inode));
    if(in == NULL){
        fprintf(stderr, "malloc failed\n");
        //shutdown()
        exit(EXIT_FAILURE);
    }
    return NULL;
}
//spar helt til sist, gjerne tenk effektivitet her
struct inode* find_inode_by_name( struct inode* parent, char* name )
{
    return NULL;
}

struct inode* load_inodes()
{
/* Read the file master_file_table and create an inode in memory
 * for every inode that is stored in the file. Set the pointers
 * between inodes correctly.
 * The file master_file_table remains unchanged.
 */
    FILE *fil;
    int id, name_len, filesize, num_entries;
    char is_dir, is_reado;
    //må endres senmere for å legge på heapen med malloc
    char *name;
    uintptr_t entries;

    //oppdatere basert på alt av data hentet inn
    int size_bytes;
    int rc;
    fil = fopen("master_file_table","rb");
    if(fil == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while( (rc = fread(&id,sizeof(int), 1, fil))) {
        fread(&name_len,sizeof(int), 1, fil);
        //Malloc her
        fread(name, sizeof(char), name_len, fil);
        fread(&is_reado, sizeof(char),1, fil);
        fread(&is_dir, sizeof(char), 1, fil);
        fread(&filesize, sizeof(int), 1, fil);
        fread(&num_entries, sizeof(int), 1, fil);
        //iterere gjennom entries num_entries antall ganger for hver node og lese antal
        //bytes som trengs for structene
        printf("%s", name);
        
    }

    if(ferror(fil)){
        fprintf(stderr, "fread fail\n");
        //free metode som må lages her for å slippe fri alle våre småp fugler (aka inoder osm blir lagd)'
        exit(EXIT_FAILURE);
    }

    fclose(fil);
    return NULL;
}

void fs_shutdown( struct inode* inode )
{

}

/* This static variable is used to change the indentation while debug_fs
 * is walking through the tree of inodes and prints information.
 */
static int indent = 0;

void debug_fs( struct inode* node )
{
    if( node == NULL ) return;
    for( int i=0; i<indent; i++ )
        printf("  ");
    if( node->is_directory )
    {
        printf("%s (id %d)\n", node->name, node->id );
        indent++;
        for( int i=0; i<node->num_entries; i++ )
        {
            struct inode* child = (struct inode*)node->entries[i];
            debug_fs( child );
        }
        indent--;
    }
    else
    {
        printf("%s (id %d size %db blocks ", node->name, node->id, node->filesize );
        for( int i=0; i<node->num_entries; i++ )
        {
            printf("%d ", (int)node->entries[i]);
        }
        printf(")\n");
    }
}

