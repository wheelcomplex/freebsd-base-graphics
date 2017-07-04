#include <linux/anon_inodes.h>
#include <linux/file.h>
#include <linux/fs.h>

struct file *
anon_inode_getfile(const char *name,
				   const struct file_operations *fops,
				   void *priv, int flags) {

	/* struct qstr this; */
	/* struct path path; */
	struct file *file;

	/* if (IS_ERR(anon_inode_inode)) */
	/* 	return ERR_PTR(-ENODEV); */

	/* if (fops->owner && !try_module_get(fops->owner)) */
	/* 	return ERR_PTR(-ENOENT); */

	/*
	 * Link the inode to a directory entry by creating a unique name
	 * using the inode sequence number.
	 */
	/* file = ERR_PTR(-ENOMEM); */
	/* this.name = name; */
	/* this.len = strlen(name); */
	/* this.hash = 0; */
	/* path.dentry = d_alloc_pseudo(anon_inode_mnt->mnt_sb, &this); */
	/* if (!path.dentry) */
		/* goto err_module; */

	/* path.mnt = mntget(anon_inode_mnt); */
	/*
	 * We know the anon_inode inode count is always greater than zero,
	 * so ihold() is safe.
	 */
	/* ihold(anon_inode_inode); */

	/* d_instantiate(path.dentry, anon_inode_inode); */

	file = alloc_file(OPEN_FMODE(flags), fops);
	if (IS_ERR(file))
		goto err_dput;

	/* file->f_mapping = anon_inode_inode->i_mapping; */

	file->f_flags = flags & (O_ACCMODE | O_NONBLOCK);
	file->private_data = priv;

	return file;

err_dput:
	/* path_put(&path); */
err_module:
	module_put(fops->owner);
	return file;


}
