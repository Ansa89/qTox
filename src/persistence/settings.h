/*
    Copyright (C) 2013 by Maxim Biro <nurupo.contributions@gmail.com>
    Copyright © 2014-2015 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QHash>
#include <QObject>
#include <QPixmap>
#include <QMutex>
#include "src/core/corestructs.h"

class ToxId;
class Profile;
namespace Db { enum class syncType; }

enum ProxyType {ptNone, ptSOCKS5, ptHTTP};

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings& getInstance();
    static void destroyInstance();
    QString getSettingsDirPath(); ///< The returned path ends with a directory separator

    void createSettingsDir(); ///< Creates a path to the settings dir, if it doesn't already exist
    void createPersonal(QString basename); ///< Write a default personnal .ini settings file for a profile

    void savePersonal(); ///< Asynchronous, saves the current profile
    void savePersonal(Profile *profile); ///< Asynchronous

    void loadGlobal();
    void loadPersonnal();
    void loadPersonnal(Profile *profile);

public slots:
    void saveGlobal(); ///< Asynchronous
    void sync(); ///< Waits for all asynchronous operations to complete

signals:
    void dhtServerListChanged();
    void smileyPackChanged();
    void emojiFontChanged();

public:
    // Getter/setters
    const QList<DhtServer>& getDhtServerList() const;
    void setDhtServerList(const QList<DhtServer>& newDhtServerList);

    bool getEnableIPv6() const;
    void setEnableIPv6(bool newValue);

    bool getMakeToxPortable() const;
    void setMakeToxPortable(bool newValue);

    bool getAutorun() const;
    void setAutorun(bool newValue);

    bool getAutostartInTray() const;
    void setAutostartInTray(bool newValue);

    bool getCloseToTray() const;
    void setCloseToTray(bool newValue);

    bool getMinimizeToTray() const;
    void setMinimizeToTray(bool newValue);

    bool getLightTrayIcon() const;
    void setLightTrayIcon(bool newValue);

    QString getStyle() const;
    void setStyle(const QString& newValue);

    bool getShowSystemTray() const;
    void setShowSystemTray(const bool& newValue);

    bool getUseEmoticons() const;
    void setUseEmoticons(bool newValue);

    QString getCurrentProfile() const;
    uint32_t getCurrentProfileId() const;
    void setCurrentProfile(QString profile);

    QString getTranslation() const;
    void setTranslation(QString newValue);

    void setAutoSaveEnabled(bool newValue);
    bool getAutoSaveEnabled() const;

    bool getForceTCP() const;
    void setForceTCP(bool newValue);

    QString getProxyAddr() const;
    void setProxyAddr(const QString& newValue);

    ProxyType getProxyType() const;
    void setProxyType(int newValue);

    int getProxyPort() const;
    void setProxyPort(int newValue);

    bool getEnableLogging() const;
    void setEnableLogging(bool newValue);

    Db::syncType getDbSyncType() const;
    void setDbSyncType(int newValue);

    int getAutoAwayTime() const;
    void setAutoAwayTime(int newValue);

    bool getCheckUpdates() const;
    void setCheckUpdates(bool newValue);

    bool getShowWindow() const;
    void setShowWindow(bool newValue);

    bool getShowInFront() const;
    void setShowInFront(bool newValue);

    bool getNotifySound() const;
    void setNotifySound(bool newValue);

    bool getGroupAlwaysNotify() const;
    void setGroupAlwaysNotify(bool newValue);

    QPixmap getSavedAvatar(const QString& ownerId);
    void saveAvatar(QPixmap& pic, const QString& ownerId);

    QByteArray getAvatarHash(const QString& ownerId);
    void saveAvatarHash(const QByteArray& hash, const QString& ownerId);

    QString getInDev() const;
    void setInDev(const QString& deviceSpecifier);

    QString getOutDev() const;
    void setOutDev(const QString& deviceSpecifier);

    bool getFilterAudio() const;
    void setFilterAudio(bool newValue);

    QString getVideoDev() const;
    void setVideoDev(const QString& deviceSpecifier);

    QSize getCamVideoRes() const;
    void setCamVideoRes(QSize newValue);

    bool isAnimationEnabled() const;
    void setAnimationEnabled(bool newValue);

    QString getSmileyPack() const;
    void setSmileyPack(const QString &value);

    int getThemeColor() const;
    void setThemeColor(const int& value);

    bool isCurstomEmojiFont() const;
    void setCurstomEmojiFont(bool value);

    QString getEmojiFontFamily() const;
    void setEmojiFontFamily(const QString &value);

    int getEmojiFontPointSize() const;
    void setEmojiFontPointSize(int value);

    QString getAutoAcceptDir(const ToxId& id) const;
    void setAutoAcceptDir(const ToxId&id, const QString& dir);

    QString getGlobalAutoAcceptDir() const;
    void setGlobalAutoAcceptDir(const QString& dir);

    // ChatView
    int getFirstColumnHandlePos() const;
    void setFirstColumnHandlePos(const int pos);

    int getSecondColumnHandlePosFromRight() const;
    void setSecondColumnHandlePosFromRight(const int pos);

    const QString& getTimestampFormat() const;
    void setTimestampFormat(const QString& format);

    const QString& getDateFormat() const;
    void setDateFormat(const QString& format);

    bool isMinimizeOnCloseEnabled() const;
    void setMinimizeOnClose(bool newValue);

    bool getStatusChangeNotificationEnabled() const;
    void setStatusChangeNotificationEnabled(bool newValue);

    // Privacy
    bool isTypingNotificationEnabled() const;
    void setTypingNotification(bool enabled);

    // State
    bool getUseNativeStyle() const;
    void setUseNativeStyle(bool value);

    QByteArray getWindowGeometry() const;
    void setWindowGeometry(const QByteArray &value);

    QByteArray getWindowState() const;
    void setWindowState(const QByteArray &value);

    QByteArray getSplitterState() const;
    void setSplitterState(const QByteArray &value);

    QString getFriendAdress(const QString &publicKey) const;
    void updateFriendAdress(const QString &newAddr);

    QString getFriendAlias(const ToxId &id) const;
    void setFriendAlias(const ToxId &id, const QString &alias);

    void removeFriendSettings(const ToxId &id);

    bool getFauxOfflineMessaging() const;
    void setFauxOfflineMessaging(bool value);

    bool getCompactLayout() const;
    void setCompactLayout(bool compact);

    bool getGroupchatPosition() const;
    void setGroupchatPosition(bool value);

    bool getAutoLogin() const;
    void setAutoLogin(bool state);

    // Assume all widgets have unique names
    // Don't use it to save every single thing you want to save, use it
    // for some general purpose widgets, such as MainWindows or Splitters,
    // which have widget->saveX() and widget->loadX() methods.
    QByteArray getWidgetData(const QString& uniqueName) const;
    void setWidgetData(const QString& uniqueName, const QByteArray& data);

    // Wrappers around getWidgetData() and setWidgetData()
    // Assume widget has a unique objectName set
    template <class T>
    void restoreGeometryState(T* widget) const
    {
        widget->restoreGeometry(getWidgetData(widget->objectName() + "Geometry"));
        widget->restoreState(getWidgetData(widget->objectName() + "State"));
    }
    template <class T>
    void saveGeometryState(const T* widget)
    {
        setWidgetData(widget->objectName() + "Geometry", widget->saveGeometry());
        setWidgetData(widget->objectName() + "State", widget->saveState());
    }

private:
    Settings();
    ~Settings();
    Settings(Settings &settings) = delete;
    Settings& operator=(const Settings&) = delete;
    static uint32_t makeProfileId(const QString& profile);

private slots:
    void savePersonal(QString profileName, QString password);

private:
    bool loaded;

    bool useCustomDhtList;
    QList<DhtServer> dhtServerList;
    int dhtServerId;
    bool dontShowDhtDialog;

    bool autoLogin;
    bool fauxOfflineMessaging;
    bool compactLayout;
    bool groupchatPosition;
    bool enableIPv6;
    QString translation;
    bool makeToxPortable;
    bool autostartInTray;
    bool closeToTray;
    bool minimizeToTray;
    bool lightTrayIcon;
    bool useEmoticons;
    bool checkUpdates;
    bool showWindow;
    bool showInFront;
    bool notifySound;
    bool groupAlwaysNotify;

    bool forceTCP;

    ProxyType proxyType;
    QString proxyAddr;
    int proxyPort;

    QString currentProfile;
    uint32_t currentProfileId;

    bool enableLogging;

    int autoAwayTime;

    QHash<QString, QByteArray> widgetSettings;
    QHash<QString, QString> autoAccept;
    bool autoSaveEnabled;
    QString globalAutoAcceptDir;

    // GUI
    bool enableSmoothAnimation;
    QString smileyPack;
    bool customEmojiFont;
    QString emojiFontFamily;
    int     emojiFontPointSize;
    bool minimizeOnClose;
    bool useNativeStyle;
    QByteArray windowGeometry;
    QByteArray windowState;
    QByteArray splitterState;
    QString style;
    bool showSystemTray;

    // ChatView
    int firstColumnHandlePos;
    int secondColumnHandlePosFromRight;
    QString timestampFormat;
    QString dateFormat;
    bool statusChangeNotificationEnabled;

    // Privacy
    bool typingNotification;
    Db::syncType dbSyncType;

    // Audio
    QString inDev;
    QString outDev;
    bool filterAudio;

    // Video
    QString videoDev;
    QSize camVideoRes;

    struct friendProp
    {
        QString alias;
        QString addr;
        QString autoAcceptDir;
    };

    QHash<QString, friendProp> friendLst;

    int themeColor;

    static QMutex bigLock;
    static Settings* settings;
    static const QString globalSettingsFile;
    static QThread* settingsThread;
};

#endif // SETTINGS_HPP
