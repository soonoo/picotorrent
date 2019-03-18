#pragma once

#include <memory>

#include <libtorrent/sha1_hash.hpp>

#include "detailstab.hpp"

class QAction;
class QTreeView;

namespace pt
{
    class FileStorageItemModel;
    struct SessionState;

    class TorrentFilesWidget : public DetailsTab
    {
    public:
        TorrentFilesWidget();

        virtual void clear() override;
        virtual void refresh(QList<TorrentHandle*> const& torrents) override;

    private:
        void onFileContextMenu(QPoint const& point);
        void onSetFilePriorities(QAction* action);

        libtorrent::sha1_hash m_currentSelection;
        QTreeView* m_filesView;
        FileStorageItemModel* m_filesModel;
        QList<TorrentHandle*> m_torrents;

        // Actions
        QAction* m_prioMaximum;
        QAction* m_prioNormal;
        QAction* m_prioLow;
        QAction* m_prioDoNotDownload;
    };
}
